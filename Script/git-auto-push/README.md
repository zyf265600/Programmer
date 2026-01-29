# Git Auto-Push for macOS

Automated daily Git commit and push with email notifications.

## ✨ Features

- ✅ Scheduled execution via macOS `launchd`
- ✅ Only commits when changes exist (no empty commits)
- ✅ Automatic `git pull --rebase` before committing
- ✅ Robust change detection using `git status --porcelain`
- ✅ Commit message: `auto push everyday`
- ✅ Email notifications (success/no-op/failure)
- ✅ Detailed email reports with stdout/stderr
- ✅ Non-interactive SSH authentication
- ✅ Production-grade error handling
- ✅ Executes once per day (even with multiple triggers)
- ✅ Auto-executes after wake (if missed scheduled time)

## 📋 Prerequisites

1. **Git repository** with remote configured
2. **SSH key authentication** set up (no password required)
3. **Mail.app** configured with email account
4. **macOS** 10.14 or later

## ⚙️ How It Works

### Execution Schedule

The system triggers twice daily (every 12 hours):
- **09:00** - Morning trigger
- **21:00** - Evening trigger (9 PM)

### Daily-Once Logic

The script automatically checks if it has already run today:
- ✅ **Not executed** → Proceeds with normal push
- ⊘ **Already executed** → Skips (avoids duplicates)

### Execute After Wake

If the computer is asleep during trigger time:
- Will execute at the next trigger time after wake
- Ensures at least one execution per day

## 🚀 Quick Start

### 1. Configure Script

Edit the configuration section in `git-auto-push.sh` (lines 16-20):

```bash
REPO_PATH="/Users/zyf/Desktop/Programmer/Script"  # Your repository path
BRANCH="main"                                       # Target branch
EMAIL_TO="zhangyifeide@gmail.com"                  # Notification recipient
EMAIL_FROM="zhangyifeide@gmail.com"                # Sender email (must match Mail.app account)
```

### 2. Test Script

```bash
cd /Users/zyf/Desktop/Programmer/Script/git-auto-push
./git-auto-push.sh
```

You should receive an email notification.

### 3. Install

```bash
./install.sh
```

The install script will automatically:
- Copy configuration file to `~/Library/LaunchAgents/`
- Load launchd task
- Verify successful installation

### 4. Test Automatic Execution

```bash
# Manual trigger
launchctl start com.user.git-auto-push

# View logs
tail -f ~/Library/Logs/git-auto-push.log
```

## 📧 Email Notifications

Each execution sends an email with one of the following states:

### SUCCESS
- Changes detected and successfully pushed
- Includes commit hash and changed file list

### NO-OP
- No changes in repository
- No action needed

### FAILURE
- Pull, commit, or push failed
- Includes detailed error information

## 🛠️ Common Commands

```bash
# Check task status
launchctl list | grep git-auto-push

# Manually trigger execution
launchctl start com.user.git-auto-push

# View logs
tail -f ~/Library/Logs/git-auto-push.log

# View error logs
tail -f ~/Library/Logs/git-auto-push.error.log

# Check last execution date
cat /tmp/git-auto-push-last-run

# Force re-execution today (for testing)
rm /tmp/git-auto-push-last-run
launchctl start com.user.git-auto-push

# Uninstall
./uninstall.sh
```

## ⚙️ Configuration

### Change Execution Time

Edit `com.user.git-auto-push.plist`:

```xml
<key>StartCalendarInterval</key>
<array>
    <dict>
        <key>Hour</key>
        <integer>9</integer>    <!-- 0-23 -->
        <key>Minute</key>
        <integer>0</integer>   <!-- 0-59 -->
    </dict>
    <dict>
        <key>Hour</key>
        <integer>21</integer>
        <key>Minute</key>
        <integer>0</integer>
    </dict>
</array>
```

Reload after changes:

```bash
launchctl unload ~/Library/LaunchAgents/com.user.git-auto-push.plist
launchctl load ~/Library/LaunchAgents/com.user.git-auto-push.plist
```

### Change Commit Message

Edit line 225 in `git-auto-push.sh`:

```bash
COMMIT_MSG="auto push everyday"  # Change to your desired commit message
```

## 🐛 Troubleshooting

### Email Not Received

1. Check if Mail.app has email account configured
2. Verify `EMAIL_FROM` matches Mail.app account
3. Check System Preferences → Privacy & Security → Automation permissions

### Git Authentication Failed

```bash
# Add SSH key to Keychain (permanent)
ssh-add --apple-use-keychain ~/.ssh/id_ed25519

# Test GitHub connection
ssh -T git@github.com
```

### Script Not Executing

```bash
# Check if task is loaded
launchctl list | grep git-auto-push

# View error logs
tail -50 ~/Library/Logs/git-auto-push.error.log

# Manual test script
./git-auto-push.sh
```

### Environment Check

Run the environment check script:

```bash
./check-environment.sh
```

## 📊 Execution Examples

### Normal Case

```
09:00 → Trigger → ✓ Execute push
21:00 → Trigger → ⊘ Skip (already executed today)
```

### Wake After Sleep

```
08:00 → Computer sleeps
09:00 → (missed trigger)
15:00 → Computer wakes
21:00 → Trigger → ✓ Execute push (first time today)
```

### Sleep All Day

```
09:00 → (computer asleep, missed)
21:00 → (computer asleep, missed)
Next day 09:00 → ✓ Execute push
```

## 🔋 Battery Friendly

- Only 2 triggers per day (morning and evening)
- Won't frequently wake computer
- Suitable for laptop use

## 📝 File Description

| File | Description |
|------|-------------|
| `git-auto-push.sh` | Main script (edit configuration) |
| `com.user.git-auto-push.plist` | launchd schedule configuration |
| `install.sh` | Installation script |
| `uninstall.sh` | Uninstallation script |
| `check-environment.sh` | Environment check tool |

## 📚 More Information

See `INSTALL.md` for detailed installation steps.

## 🔒 Security Notes

- SSH keys should be added to macOS Keychain
- Don't commit sensitive information to repository
- Email content may include repository paths and file names

## 📄 License

Free to use and modify for personal or commercial projects.
