# Linux Command Summary - Concise Version

## 1. File & Directory Operations

### `pwd`

Print current directory

```bash
pwd
```

### `ls`

List directory contents

```bash
ls
ls -l        # detailed list
ls -a        # include hidden files
ls -lh       # human-readable sizes
```

### `cd`

Change directory

```bash
cd /path/to/dir
cd ~          # home directory
cd ..         # parent directory
```

### `mkdir`

Create directory

```bash
mkdir test
mkdir -p a/b/c   # create nested directories
```

### `rm`

Remove files or directories

```bash
rm file.txt
rm -r folder
rm -rf folder    # force delete (dangerous)
```

### `cp`

Copy files/directories

```bash
cp a.txt b.txt
cp -r dir1 dir2
```

### `mv`

Move or rename

```bash
mv old.txt new.txt
mv file.txt folder/
```

------

## 2. File Viewing & Editing

### `cat`

Print file content

```bash
cat file.txt
```

### `less`

View large files (recommended)

```bash
less file.txt
```

Controls:

- `q` quit
- `/text` search
- `n` next match

### `head` / `tail`

View beginning or end of file

```bash
head file.txt
tail file.txt
tail -f log.txt   # real-time log
```

### `touch`

Create empty file

```bash
touch test.txt
```

### `nano` / `vim`

Terminal text editors

```bash
nano file.txt
vim file.txt
```

------

## 3. Search & Text Processing

### `grep`

Search text

```bash
grep "main" file.c
grep -r "TODO" .
```

### `find`

Find files

```bash
find . -name "*.cpp"
find . -type f
```

### `wc`

Word / line / character count

```bash
wc file.txt
wc -l file.txt
```

------

## 4. Permissions & Ownership

### `chmod`

Change permissions

```bash
chmod 755 script.sh
chmod +x script.sh
```

### `chown`

Change owner (usually needs sudo)

```bash
sudo chown user file.txt
```

### `ls -l` permissions meaning

```
-rwxr-xr--
```

- r = read
- w = write
- x = execute

------

## 5. Process & System Monitoring

### `ps`

Show running processes

```bash
ps aux
```

### `top`

Real-time process monitor

```bash
top
```

(macOS alternative: `htop` via Homebrew)

### `kill`

Terminate process

```bash
kill PID
kill -9 PID
```

------

## 6. Networking

### `ping`

Test connectivity

```bash
ping google.com
```

### `curl`

HTTP requests

```bash
curl https://example.com
curl -X POST url
```

### `wget`

Download files (not installed by default)

```bash
brew install wget
wget url
```

------

## 7. Disk & System Info

### `df`

Disk usage

```bash
df -h
```

### `du`

Directory size

```bash
du -sh folder
```

### `uname`

System info

```bash
uname -a
```

### `whoami`

Current user

```bash
whoami
```

------

## 8. Package Management (macOS-specific but Linux-style)

### Homebrew

Most Linux-like package manager on macOS

```bash
brew install git
brew update
brew upgrade
brew list
```

------

## 9. Redirection & Pipes (Very Important)

### Output redirection

```bash
ls > out.txt
ls >> out.txt
```

### Pipes

```bash
ps aux | grep python
cat file.txt | wc -l
```

------

## 10. Environment & Shell

### `echo`

Print text or variables

```bash
echo "hello"
echo $PATH
```

### `export`

Set environment variable

```bash
export MY_VAR=123
```

### `source`

Reload config

```bash
source ~/.zshrc
```

------

## Notes: macOS vs Linux Differences

- macOS uses **BSD coreutils**, Linux uses **GNU coreutils**
- Some flags differ (`sed`, `grep`, `date`)
- You can install GNU tools:

```bash
brew install coreutils
```

