#!/bin/bash

################################################################################
# Environment Check Script
# 
# Validates that your system is properly configured for git-auto-push
################################################################################

set -u

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Counters
PASS=0
FAIL=0
WARN=0

echo ""
echo "════════════════════════════════════════════════════════════════"
echo "  Git Auto-Push Environment Check"
echo "════════════════════════════════════════════════════════════════"
echo ""

# Helper functions
pass() {
    echo -e "${GREEN}✓${NC} $1"
    ((PASS++))
}

fail() {
    echo -e "${RED}✗${NC} $1"
    ((FAIL++))
}

warn() {
    echo -e "${YELLOW}⚠${NC} $1"
    ((WARN++))
}

info() {
    echo -e "${BLUE}ℹ${NC} $1"
}

section() {
    echo ""
    echo "─────────────────────────────────────────────────────────────────"
    echo "$1"
    echo "─────────────────────────────────────────────────────────────────"
}

#------------------------------------------------------------------------------
# Check 1: Git installation
#------------------------------------------------------------------------------

section "1. Git Installation"

if command -v git &> /dev/null; then
    GIT_VERSION=$(git --version)
    pass "Git is installed: $GIT_VERSION"
else
    fail "Git is not installed"
    info "Install with: xcode-select --install"
fi

#------------------------------------------------------------------------------
# Check 2: Repository
#------------------------------------------------------------------------------

section "2. Repository Configuration"

REPO_PATH="/Users/zyf/Desktop/Programmer/Script"

if [ -d "$REPO_PATH" ]; then
    pass "Repository directory exists: $REPO_PATH"
    
    if [ -d "$REPO_PATH/.git" ]; then
        pass "Valid Git repository"
        
        cd "$REPO_PATH" || exit 1
        
        # Check remote
        if git remote -v | grep -q "origin"; then
            REMOTE_URL=$(git remote get-url origin 2>/dev/null)
            pass "Remote 'origin' configured: $REMOTE_URL"
        else
            fail "No remote 'origin' configured"
            info "Add with: git remote add origin <url>"
        fi
        
        # Check branch
        CURRENT_BRANCH=$(git branch --show-current 2>/dev/null)
        if [ -n "$CURRENT_BRANCH" ]; then
            pass "Current branch: $CURRENT_BRANCH"
        else
            warn "Could not determine current branch"
        fi
        
        # Check for changes
        if [ -z "$(git status --porcelain)" ]; then
            info "Working directory is clean (no changes to commit)"
        else
            info "Working directory has uncommitted changes"
        fi
        
    else
        fail "Not a Git repository (no .git directory)"
        info "Initialize with: cd '$REPO_PATH' && git init"
    fi
else
    fail "Repository directory does not exist: $REPO_PATH"
    info "Update REPO_PATH in git-auto-push.sh to your repository location"
fi

#------------------------------------------------------------------------------
# Check 3: SSH Authentication
#------------------------------------------------------------------------------

section "3. SSH Authentication"

if [ -d "$HOME/.ssh" ]; then
    pass "SSH directory exists"
    
    # Check for SSH keys
    if ls ~/.ssh/id_* 2>/dev/null | grep -v "\.pub$" | head -n 1 &> /dev/null; then
        SSH_KEY=$(ls ~/.ssh/id_* 2>/dev/null | grep -v "\.pub$" | head -n 1)
        pass "SSH key found: $(basename "$SSH_KEY")"
        
        # Check if key is loaded
        if ssh-add -l &> /dev/null; then
            pass "SSH agent is running"
            
            if ssh-add -l | grep -q "$(basename "$SSH_KEY" | cut -d. -f1)"; then
                pass "SSH key is loaded in agent"
            else
                warn "SSH key is not loaded in agent"
                info "Load with: ssh-add $SSH_KEY"
            fi
        else
            warn "SSH agent is not running"
            info "Start with: eval \$(ssh-agent) && ssh-add $SSH_KEY"
        fi
        
    else
        fail "No SSH keys found in ~/.ssh/"
        info "Generate with: ssh-keygen -t ed25519 -C 'your-email@example.com'"
    fi
    
    # Test GitHub connection (if using GitHub)
    if grep -q "github.com" "$REPO_PATH/.git/config" 2>/dev/null; then
        info "Testing GitHub SSH connection..."
        if ssh -T git@github.com 2>&1 | grep -q "successfully authenticated"; then
            pass "GitHub SSH authentication successful"
        else
            warn "GitHub SSH authentication failed"
            info "Add your SSH key to GitHub: https://github.com/settings/keys"
        fi
    fi
    
else
    fail "SSH directory does not exist: $HOME/.ssh"
    info "Create with: mkdir -p ~/.ssh && chmod 700 ~/.ssh"
fi

#------------------------------------------------------------------------------
# Check 4: Mail.app Configuration
#------------------------------------------------------------------------------

section "4. Mail.app Configuration"

if [ -d "/Applications/Mail.app" ]; then
    pass "Mail.app is installed"
    
    # Check if Mail.app has accounts configured
    if osascript -e 'tell application "Mail" to get name of every account' 2>/dev/null | grep -q "."; then
        ACCOUNTS=$(osascript -e 'tell application "Mail" to get name of every account' 2>/dev/null)
        pass "Mail.app accounts configured: $ACCOUNTS"
    else
        warn "No accounts configured in Mail.app"
        info "Configure Mail.app with an email account before using auto-push"
    fi
    
    # Test AppleScript access
    if osascript -e 'tell application "Mail" to get name' &> /dev/null; then
        pass "AppleScript can access Mail.app"
    else
        warn "AppleScript cannot access Mail.app"
        info "Grant permission in System Preferences > Security & Privacy > Automation"
    fi
    
else
    fail "Mail.app is not installed"
fi

#------------------------------------------------------------------------------
# Check 5: launchd Configuration
#------------------------------------------------------------------------------

section "5. launchd Configuration"

PLIST_SRC="./com.user.git-auto-push.plist"
PLIST_DST="$HOME/Library/LaunchAgents/com.user.git-auto-push.plist"

if [ -f "$PLIST_SRC" ]; then
    pass "Launch agent plist file exists"
    
    # Validate XML
    if plutil -lint "$PLIST_SRC" &> /dev/null; then
        pass "Plist file is valid XML"
    else
        fail "Plist file is not valid XML"
        info "Fix XML syntax errors in $PLIST_SRC"
    fi
    
else
    fail "Launch agent plist not found: $PLIST_SRC"
fi

# Check if installed
if [ -f "$PLIST_DST" ]; then
    pass "Launch agent is installed: $PLIST_DST"
    
    # Check if loaded
    if launchctl list | grep -q "com.user.git-auto-push"; then
        pass "Launch agent is loaded"
        
        # Show schedule
        HOUR=$(plutil -extract StartCalendarInterval.Hour raw "$PLIST_DST" 2>/dev/null)
        MINUTE=$(plutil -extract StartCalendarInterval.Minute raw "$PLIST_DST" 2>/dev/null)
        if [ -n "$HOUR" ] && [ -n "$MINUTE" ]; then
            info "Scheduled to run daily at $(printf "%02d:%02d" "$HOUR" "$MINUTE")"
        fi
        
    else
        warn "Launch agent is installed but not loaded"
        info "Load with: launchctl load $PLIST_DST"
    fi
else
    info "Launch agent not yet installed"
    info "Install with: cp $PLIST_SRC $PLIST_DST && launchctl load $PLIST_DST"
fi

#------------------------------------------------------------------------------
# Check 6: Script Configuration
#------------------------------------------------------------------------------

section "6. Script Configuration"

SCRIPT_PATH="./git-auto-push.sh"

if [ -f "$SCRIPT_PATH" ]; then
    pass "Script file exists"
    
    # Check execute permission
    if [ -x "$SCRIPT_PATH" ]; then
        pass "Script is executable"
    else
        fail "Script is not executable"
        info "Fix with: chmod +x $SCRIPT_PATH"
    fi
    
    # Check if configured
    if grep -q "your-email@example.com" "$SCRIPT_PATH"; then
        warn "Email not configured (still using example email)"
        info "Edit EMAIL_TO and EMAIL_FROM in $SCRIPT_PATH"
    else
        pass "Email appears to be configured"
    fi
    
else
    fail "Script file not found: $SCRIPT_PATH"
fi

#------------------------------------------------------------------------------
# Check 7: Log Directory
#------------------------------------------------------------------------------

section "7. Log Directory"

LOG_DIR="$HOME/Library/Logs"

if [ -d "$LOG_DIR" ]; then
    pass "Log directory exists: $LOG_DIR"
    
    # Check if writable
    if [ -w "$LOG_DIR" ]; then
        pass "Log directory is writable"
    else
        fail "Log directory is not writable"
    fi
    
    # Check existing logs
    if [ -f "$LOG_DIR/git-auto-push.log" ]; then
        LOG_SIZE=$(du -h "$LOG_DIR/git-auto-push.log" | cut -f1)
        info "Existing log file: $LOG_SIZE"
    else
        info "No existing log file (will be created on first run)"
    fi
    
else
    fail "Log directory does not exist: $LOG_DIR"
fi

#------------------------------------------------------------------------------
# Summary
#------------------------------------------------------------------------------

echo ""
echo "════════════════════════════════════════════════════════════════"
echo "  Summary"
echo "════════════════════════════════════════════════════════════════"
echo ""
echo -e "${GREEN}Passed:${NC}  $PASS"
echo -e "${YELLOW}Warnings:${NC} $WARN"
echo -e "${RED}Failed:${NC}  $FAIL"
echo ""

if [ $FAIL -eq 0 ]; then
    if [ $WARN -eq 0 ]; then
        echo -e "${GREEN}✓ Environment is ready!${NC}"
        echo ""
        echo "Next steps:"
        echo "  1. Edit configuration in git-auto-push.sh"
        echo "  2. Test: ./git-auto-push.sh"
        echo "  3. Install: cp com.user.git-auto-push.plist ~/Library/LaunchAgents/"
        echo "  4. Load: launchctl load ~/Library/LaunchAgents/com.user.git-auto-push.plist"
    else
        echo -e "${YELLOW}⚠ Environment is mostly ready (some warnings)${NC}"
        echo "Review warnings above and fix if necessary."
    fi
else
    echo -e "${RED}✗ Environment has issues that need to be fixed${NC}"
    echo "Review failed checks above and follow the suggestions."
fi

echo ""
echo "════════════════════════════════════════════════════════════════"
echo ""
