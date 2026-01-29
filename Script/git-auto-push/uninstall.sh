#!/bin/bash

################################################################################
# Git Auto-Push Uninstallation Script
# 
# Removes the launchd job and optionally cleans up logs
################################################################################

set -euo pipefail

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Files
PLIST_DST="$HOME/Library/LaunchAgents/com.user.git-auto-push.plist"
LOG_FILE="$HOME/Library/Logs/git-auto-push.log"
ERROR_LOG="$HOME/Library/Logs/git-auto-push.error.log"

echo ""
echo "════════════════════════════════════════════════════════════════"
echo "  Git Auto-Push Uninstallation"
echo "════════════════════════════════════════════════════════════════"
echo ""

# Check if installed
if [ ! -f "$PLIST_DST" ]; then
    echo -e "${YELLOW}⚠ Launch agent is not installed${NC}"
    echo "Nothing to uninstall."
    exit 0
fi

# Confirm uninstallation
echo -e "${YELLOW}This will remove the Git Auto-Push automation.${NC}"
echo ""
read -p "Continue with uninstallation? (y/n) " -n 1 -r
echo ""
echo ""

if [[ ! $REPLY =~ ^[Yy]$ ]]; then
    echo "Uninstallation cancelled."
    exit 0
fi

# Unload the job
echo "→ Unloading launch agent..."
if launchctl list | grep -q "com.user.git-auto-push"; then
    if launchctl unload "$PLIST_DST"; then
        echo -e "${GREEN}✓ Launch agent unloaded${NC}"
    else
        echo -e "${RED}✗ Failed to unload launch agent${NC}"
        echo "Continuing anyway..."
    fi
else
    echo -e "${YELLOW}⚠ Launch agent was not running${NC}"
fi
echo ""

# Remove plist
echo "→ Removing plist file..."
if rm -f "$PLIST_DST"; then
    echo -e "${GREEN}✓ Plist removed${NC}"
else
    echo -e "${RED}✗ Failed to remove plist${NC}"
fi
echo ""

# Ask about logs
if [ -f "$LOG_FILE" ] || [ -f "$ERROR_LOG" ]; then
    echo ""
    read -p "Remove log files? (y/n) " -n 1 -r
    echo ""
    echo ""
    
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo "→ Removing log files..."
        rm -f "$LOG_FILE" "$ERROR_LOG"
        echo -e "${GREEN}✓ Logs removed${NC}"
        echo ""
    else
        echo "Log files retained:"
        [ -f "$LOG_FILE" ] && echo "  - $LOG_FILE"
        [ -f "$ERROR_LOG" ] && echo "  - $ERROR_LOG"
        echo ""
    fi
fi

# Verify removal
if [ ! -f "$PLIST_DST" ] && ! launchctl list | grep -q "com.user.git-auto-push"; then
    echo "════════════════════════════════════════════════════════════════"
    echo -e "${GREEN}✓ Uninstallation Complete!${NC}"
    echo "════════════════════════════════════════════════════════════════"
    echo ""
    echo "The Git Auto-Push automation has been removed."
    echo ""
    echo "The script files in this directory are still available if you"
    echo "want to reinstall later."
    echo ""
else
    echo -e "${YELLOW}⚠ Uninstallation may not be complete${NC}"
    echo ""
    echo "Manual cleanup:"
    echo "  rm -f $PLIST_DST"
    echo "  launchctl remove com.user.git-auto-push"
    echo ""
fi
