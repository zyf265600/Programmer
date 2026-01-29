#!/bin/bash

################################################################################
# Git Auto-Push Installation Script
# 
# Installs the launchd job and validates configuration
################################################################################

set -euo pipefail

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Files
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PLIST_SRC="$SCRIPT_DIR/com.user.git-auto-push.plist"
PLIST_DST="$HOME/Library/LaunchAgents/com.user.git-auto-push.plist"
SCRIPT_PATH="$SCRIPT_DIR/git-auto-push.sh"

echo ""
echo "════════════════════════════════════════════════════════════════"
echo "  Git Auto-Push Installation"
echo "════════════════════════════════════════════════════════════════"
echo ""

# Check if script exists
if [ ! -f "$SCRIPT_PATH" ]; then
    echo -e "${RED}✗ Error: git-auto-push.sh not found${NC}"
    echo "Expected location: $SCRIPT_PATH"
    exit 1
fi

# Check if plist exists
if [ ! -f "$PLIST_SRC" ]; then
    echo -e "${RED}✗ Error: com.user.git-auto-push.plist not found${NC}"
    echo "Expected location: $PLIST_SRC"
    exit 1
fi

# Validate plist
echo "→ Validating plist file..."
if ! plutil -lint "$PLIST_SRC" &> /dev/null; then
    echo -e "${RED}✗ Error: plist file is not valid XML${NC}"
    exit 1
fi
echo -e "${GREEN}✓ Plist file is valid${NC}"
echo ""

# Check if script is executable
if [ ! -x "$SCRIPT_PATH" ]; then
    echo "→ Making script executable..."
    chmod +x "$SCRIPT_PATH"
    echo -e "${GREEN}✓ Script is now executable${NC}"
    echo ""
fi

# Check if already installed
if [ -f "$PLIST_DST" ]; then
    echo -e "${YELLOW}⚠ Launch agent is already installed${NC}"
    echo ""
    read -p "Uninstall existing and reinstall? (y/n) " -n 1 -r
    echo ""
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo "→ Unloading existing job..."
        launchctl unload "$PLIST_DST" 2>/dev/null || true
        rm -f "$PLIST_DST"
        echo -e "${GREEN}✓ Existing installation removed${NC}"
        echo ""
    else
        echo "Installation cancelled."
        exit 0
    fi
fi

# Create LaunchAgents directory if it doesn't exist
if [ ! -d "$HOME/Library/LaunchAgents" ]; then
    echo "→ Creating LaunchAgents directory..."
    mkdir -p "$HOME/Library/LaunchAgents"
    echo -e "${GREEN}✓ Directory created${NC}"
    echo ""
fi

# Copy plist
echo "→ Installing launch agent..."
cp "$PLIST_SRC" "$PLIST_DST"
echo -e "${GREEN}✓ Plist copied to $PLIST_DST${NC}"
echo ""

# Load the job
echo "→ Loading launch agent..."
if launchctl load "$PLIST_DST"; then
    echo -e "${GREEN}✓ Launch agent loaded successfully${NC}"
else
    echo -e "${RED}✗ Failed to load launch agent${NC}"
    exit 1
fi
echo ""

# Verify it's loaded
if launchctl list | grep -q "com.user.git-auto-push"; then
    echo -e "${GREEN}✓ Launch agent is active${NC}"
else
    echo -e "${RED}✗ Launch agent is not active${NC}"
    exit 1
fi
echo ""

# Show schedule
HOUR=$(plutil -extract StartCalendarInterval.Hour raw "$PLIST_DST" 2>/dev/null || echo "?")
MINUTE=$(plutil -extract StartCalendarInterval.Minute raw "$PLIST_DST" 2>/dev/null || echo "?")
echo "════════════════════════════════════════════════════════════════"
echo -e "${GREEN}✓ Installation Complete!${NC}"
echo "════════════════════════════════════════════════════════════════"
echo ""
echo "Schedule: Daily at $(printf "%02d:%02d" "$HOUR" "$MINUTE")"
echo "Logs: ~/Library/Logs/git-auto-push.log"
echo ""
echo "Next steps:"
echo "  1. Test manually: $SCRIPT_PATH"
echo "  2. Test launchd: launchctl start com.user.git-auto-push"
echo "  3. Check logs: tail -f ~/Library/Logs/git-auto-push.log"
echo ""
echo "To uninstall, run: ./uninstall.sh"
echo ""
