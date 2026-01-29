# Installation Guide

## 📋 Pre-Installation Check

Run the environment check tool:

```bash
cd /Users/zyf/Desktop/Programmer/Script/git-auto-push
./check-environment.sh
```

Ensure all checks pass (especially Git, SSH, Mail.app).

## 🔧 Configuration Steps

### 1. Configure Script

Edit `git-auto-push.sh` (lines 16-20):

```bash
REPO_PATH="/Users/zyf/Desktop/Programmer"  # Your repository path
BRANCH="main"                                       # Branch name
EMAIL_TO="zhangyifeide@gmail.com"                  # Recipient email
EMAIL_FROM="zhangyifeide@gmail.com"                # Sender email (must match Mail.app)
```

### 2. Configure Mail.app

1. Open Mail.app: `open -a Mail`
2. Add Gmail account (if not already added)
3. Ensure account can send emails normally

### 3. Configure SSH Key (if not done)

```bash
# Add key to Keychain (permanent)
ssh-add --apple-use-keychain ~/.ssh/id_ed25519

# Test connection
ssh -T git@github.com
```

## 🚀 Installation

### Method 1: Using Install Script (Recommended)

```bash
cd /Users/zyf/Desktop/Programmer/Script/git-auto-push
./install.sh
```

The install script will:
- ✅ Validate configuration files
- ✅ Copy plist to LaunchAgents
- ✅ Load launchd task
- ✅ Display installation status

### Method 2: Manual Installation

```bash
# 1. Copy configuration file
cp com.user.git-auto-push.plist ~/Library/LaunchAgents/

# 2. Load task
launchctl load ~/Library/LaunchAgents/com.user.git-auto-push.plist

# 3. Verify
launchctl list | grep git-auto-push
```

## ✅ Verify Installation

### 1. Check Task Status

```bash
launchctl list | grep git-auto-push
```

Expected output:
```
-	0	com.user.git-auto-push
```

### 2. Manual Trigger Test

```bash
launchctl start com.user.git-auto-push
```

### 3. View Logs

```bash
tail -f ~/Library/Logs/git-auto-push.log
```

### 4. Check Email

Check your email inbox, you should receive an execution result notification.

## 🔄 Update Configuration

After modifying configuration, reload:

```bash
# 1. Unload
launchctl unload ~/Library/LaunchAgents/com.user.git-auto-push.plist

# 2. Edit configuration files
nano git-auto-push.sh
# or
nano com.user.git-auto-push.plist

# 3. Reinstall
./install.sh
```

## 🗑️ Uninstall

```bash
./uninstall.sh
```

Or manually uninstall:

```bash
launchctl unload ~/Library/LaunchAgents/com.user.git-auto-push.plist
rm ~/Library/LaunchAgents/com.user.git-auto-push.plist
```

## ❓ FAQ

### Q: Not executing after installation?

**Check:**
```bash
# 1. Is task loaded?
launchctl list | grep git-auto-push

# 2. View error logs
tail -50 ~/Library/Logs/git-auto-push.error.log

# 3. Manual test
./git-auto-push.sh
```

### Q: Email sending failed?

**Check:**
1. Is Mail.app account configured?
2. Does `EMAIL_FROM` match Mail.app account?
3. System Preferences → Privacy & Security → Automation permissions

### Q: Git push failed?

**Check:**
```bash
# Is SSH key loaded?
ssh-add -l

# Test GitHub connection
ssh -T git@github.com
```

## 📞 Get Help

- See `README.md` for complete documentation
- Run `./check-environment.sh` to diagnose issues
- View logs: `~/Library/Logs/git-auto-push.log`
