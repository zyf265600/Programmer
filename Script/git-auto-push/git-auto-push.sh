#!/bin/bash

################################################################################
# Git Auto-Push Script for macOS
# 
# Automatically commits and pushes changes to a Git repository with email
# notifications. Designed for unattended execution via launchd.
################################################################################

set -euo pipefail

#------------------------------------------------------------------------------
# CONFIGURATION - Edit these values
#------------------------------------------------------------------------------

REPO_PATH="/Users/zyf/Desktop/Programmer"
BRANCH="main"
EMAIL_TO="zhangyifeide@gmail.com"
EMAIL_FROM="zhangyifeide@gmail.com"
EMAIL_SUBJECT="Git Auto-Push Report"

# Explicitly set PATH for launchd environment
export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

#------------------------------------------------------------------------------
# CONSTANTS
#------------------------------------------------------------------------------

TIMESTAMP=$(date '+%Y-%m-%d %H:%M:%S')
TODAY=$(date '+%Y-%m-%d')
HOSTNAME=$(hostname)
LOG_FILE="/tmp/git-auto-push-$$.log"
LAST_RUN_FILE="/tmp/git-auto-push-last-run"
RESULT="UNKNOWN"
DETAILS=""

#------------------------------------------------------------------------------
# UTILITY FUNCTIONS
#------------------------------------------------------------------------------

# Clean up temporary files on exit
cleanup() {
    rm -f "$LOG_FILE"
}
trap cleanup EXIT

# Log message to both stdout and log file
log() {
    echo "$1" | tee -a "$LOG_FILE"
}

# Send email notification using Mail.app via AppleScript
send_email() {
    local status="$1"
    local body="$2"
    
    # Escape quotes and backslashes for AppleScript
    local escaped_body=$(echo "$body" | sed 's/\\/\\\\/g' | sed 's/"/\\"/g')
    
    osascript <<EOF
tell application "Mail"
    set newMessage to make new outgoing message with properties {subject:"$EMAIL_SUBJECT - $status", content:"$escaped_body", visible:false}
    tell newMessage
        make new to recipient at end of to recipients with properties {address:"$EMAIL_TO"}
        set sender to "$EMAIL_FROM"
        send
    end tell
end tell
EOF
    
    if [ $? -eq 0 ]; then
        log "✓ Email notification sent successfully"
    else
        log "✗ Failed to send email notification"
    fi
}

# Format email body
format_email_body() {
    local status="$1"
    local details="$2"
    
    cat <<EOF
Git Auto-Push Status Report
═══════════════════════════════════════

Status:      $status
Timestamp:   $TIMESTAMP
Hostname:    $HOSTNAME
Repository:  $REPO_PATH
Branch:      $BRANCH

Details:
───────────────────────────────────────
$details
═══════════════════════════════════════

This is an automated message from Git Auto-Push.
EOF
}

#------------------------------------------------------------------------------
# MAIN LOGIC
#------------------------------------------------------------------------------

main() {
    log "════════════════════════════════════════════════════════════════"
    log "Git Auto-Push execution started at $TIMESTAMP"
    log "════════════════════════════════════════════════════════════════"
    
    #--------------------------------------------------------------------------
    # CHECK: Has it already run today?
    #--------------------------------------------------------------------------
    
    if [ -f "$LAST_RUN_FILE" ]; then
        LAST_RUN_DATE=$(cat "$LAST_RUN_FILE")
        if [ "$LAST_RUN_DATE" = "$TODAY" ]; then
            log "✓ Already ran today ($TODAY). Skipping execution."
            log "Next run will be after midnight."
            exit 0
        fi
    fi
    
    log "→ First run of the day. Proceeding..."
    log ""
    
    # Validate repository path
    if [ ! -d "$REPO_PATH" ]; then
        RESULT="FAILURE"
        DETAILS="Error: Repository path does not exist: $REPO_PATH"
        log "✗ $DETAILS"
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 1
    fi
    
    # Change to repository directory
    cd "$REPO_PATH" || {
        RESULT="FAILURE"
        DETAILS="Error: Failed to change directory to: $REPO_PATH"
        log "✗ $DETAILS"
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 1
    }
    
    # Verify it's a git repository
    if [ ! -d ".git" ]; then
        RESULT="FAILURE"
        DETAILS="Error: Not a git repository: $REPO_PATH"
        log "✗ $DETAILS"
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 1
    fi
    
    log "Repository: $REPO_PATH"
    log "Branch: $BRANCH"
    log ""
    
    #--------------------------------------------------------------------------
    # STAGE 1: Pull with rebase
    #--------------------------------------------------------------------------
    
    log "→ Stage 1: Pulling latest changes with rebase..."
    
    # Check for unstaged changes that would block rebase
    if [ -n "$(git status --porcelain)" ]; then
        log "⚠ Unstaged changes detected, stashing before pull..."
        if ! git stash push -m "Auto-stash before pull: $TIMESTAMP" >> "$LOG_FILE" 2>&1; then
            RESULT="FAILURE"
            DETAILS="Failed to stash changes before pull\n\nOutput:\n$(cat "$LOG_FILE")"
            log "✗ Stash failed"
            send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
            exit 1
        fi
        STASHED=true
    else
        STASHED=false
    fi
    
    # Pull with rebase
    if ! git pull --rebase origin "$BRANCH" >> "$LOG_FILE" 2>&1; then
        RESULT="FAILURE"
        DETAILS="Failed to pull with rebase from origin/$BRANCH\n\nOutput:\n$(cat "$LOG_FILE")"
        log "✗ Pull failed"
        
        # Restore stashed changes if we stashed them
        if [ "$STASHED" = true ]; then
            log "→ Restoring stashed changes..."
            git stash pop >> "$LOG_FILE" 2>&1 || true
        fi
        
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 1
    fi
    
    # Restore stashed changes after successful pull
    if [ "$STASHED" = true ]; then
        log "→ Restoring stashed changes after pull..."
        if ! git stash pop >> "$LOG_FILE" 2>&1; then
            log "⚠ Stash pop had conflicts, but continuing..."
        fi
    fi
    
    log "✓ Pull completed successfully"
    log ""
    
    #--------------------------------------------------------------------------
    # STAGE 2: Detect changes
    #--------------------------------------------------------------------------
    
    log "→ Stage 2: Detecting changes..."
    
    # Check for any changes (tracked or untracked)
    if [ -z "$(git status --porcelain)" ]; then
        RESULT="NO-OP"
        DETAILS="No changes detected in the repository.\n\nRepository is up to date."
        log "✓ No changes detected - nothing to commit"
        
        # Record today's execution even if no changes
        echo "$TODAY" > "$LAST_RUN_FILE"
        
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 0
    fi
    
    # Show what changed
    CHANGES=$(git status --porcelain)
    log "✓ Changes detected:"
    echo "$CHANGES" | while IFS= read -r line; do
        log "  $line"
    done
    log ""
    
    #--------------------------------------------------------------------------
    # STAGE 3: Add all changes
    #--------------------------------------------------------------------------
    
    log "→ Stage 3: Staging changes..."
    
    if ! git add -A >> "$LOG_FILE" 2>&1; then
        RESULT="FAILURE"
        DETAILS="Failed to stage changes\n\nOutput:\n$(cat "$LOG_FILE")"
        log "✗ Failed to stage changes"
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 1
    fi
    
    log "✓ Changes staged successfully"
    log ""
    
    #--------------------------------------------------------------------------
    # STAGE 4: Commit
    #--------------------------------------------------------------------------
    
    log "→ Stage 4: Creating commit..."
    
    COMMIT_MSG="auto push everyday"
    
    if ! git commit -m "$COMMIT_MSG" >> "$LOG_FILE" 2>&1; then
        RESULT="FAILURE"
        DETAILS="Failed to create commit\n\nOutput:\n$(cat "$LOG_FILE")"
        log "✗ Commit failed"
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 1
    fi
    
    COMMIT_HASH=$(git rev-parse --short HEAD)
    log "✓ Commit created: $COMMIT_HASH"
    log ""
    
    #--------------------------------------------------------------------------
    # STAGE 5: Push
    #--------------------------------------------------------------------------
    
    log "→ Stage 5: Pushing to remote..."
    
    if ! git push origin "$BRANCH" >> "$LOG_FILE" 2>&1; then
        RESULT="FAILURE"
        DETAILS="Failed to push to origin/$BRANCH\n\nCommit was created but push failed.\nCommit hash: $COMMIT_HASH\n\nOutput:\n$(cat "$LOG_FILE")"
        log "✗ Push failed (commit was created locally)"
        send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
        exit 1
    fi
    
    log "✓ Push completed successfully"
    log ""
    
    #--------------------------------------------------------------------------
    # SUCCESS
    #--------------------------------------------------------------------------
    
    RESULT="SUCCESS"
    DETAILS="Changes committed and pushed successfully.\n\nCommit: $COMMIT_HASH\nMessage: $COMMIT_MSG\n\nChanges:\n$CHANGES"
    
    log "════════════════════════════════════════════════════════════════"
    log "✓ SUCCESS: All operations completed"
    log "════════════════════════════════════════════════════════════════"
    
    # Record today's execution
    echo "$TODAY" > "$LAST_RUN_FILE"
    
    send_email "$RESULT" "$(format_email_body "$RESULT" "$DETAILS")"
}

# Execute main function
main
