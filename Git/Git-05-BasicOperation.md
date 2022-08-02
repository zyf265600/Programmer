# Git 基本操作

Git 的工作就是创建和保存你项目的快照及与之后的快照进行对比。

本章将对有关创建与提交你的项目快照的命令作介绍。

Git 常用的是以下 6 个命令：**git clone、git push、git add 、git commit、git checkout、git pull**，后面我们会详细介绍。

![img](https://www.runoob.com/wp-content/uploads/2015/02/git-command.jpg)

**说明** 

- Workspace：工作区
- Staging area / index：暂存区/缓存区
- Local repository：版本库或本地仓库
- Remote repository：远程仓库

一个简单的操作步骤：

```
$ git init    
$ git add .    
$ git commit  
```

- git init - 初始化一个仓库。
- git add . - 添加所有文件到暂存区。
- git commit - 将暂存区内容添加到本地仓库中。



## 创建仓库命令

下面列出了 git 创建仓库的命令：

### git init (初始化仓库)：

**git init** 命令用于在目录中创建新的 Git 仓库。

在目录中执行 **git init** 就可以创建一个 Git 仓库了。

例如我们在当前目录下创建一个名为 runoob 的项目：

```
$ mkdir runoob #创建新文件夹
$ cd runoob/
$ git init
Initialized empty Git repository in /Users/tianqixin/www/runoob/.git/
# 初始化空 Git 仓库完毕。
```

现在你可以看到在你的项目中生成了 **.git** 这个子目录，这就是你的 Git 仓库了，所有有关你的此项目的快照数据都存放在这里。

***.git** 默认是隐藏的，可以用 ls -a 命令查看：*

```
ls -a
.    ..    .git
```



### git clone (克隆命令):

**git clone** 拷贝一个 Git 仓库到本地，让自己能够查看该项目，或者进行修改。

拷贝项目命令格式如下：

```
 git clone [url]
```

**[url]** 是你要拷贝的项目。

例如我们拷贝 Github 上的项目：

```
$ git clone https://github.com/tianqixin/runoob-git-test
Cloning into 'runoob-git-test'...
remote: Enumerating objects: 12, done.
remote: Total 12 (delta 0), reused 0 (delta 0), pack-reused 12
Unpacking objects: 100% (12/12), done.
```

拷贝完成后，在**当前目录下**会生成一个 runoob-git-test 目录：

```
$ cd simplegit/
$ ls
README.md    runoob-test.txt    test.txt
```

上述操作将复制该项目的全部记录。

```
$ ls -a
.        ..        .git        README.md    runoob-test.txt    test.txt
$ cd .git 
$ ls
HEAD        description    index        logs        packed-refs
config        hooks        info        objects        refs
```

默认情况下，Git 会按照你提供的 URL 所指向的项目的名称创建你的本地项目目录。 通常就是该 URL 最后一个 / 之后的项目名称。***如果你想要一个不一样的名字， 你可以在该命令后加上你想要的名称。***

例如，以下实例拷贝远程 git 项目，本地项目名为 **another-runoob-name**：

```
$ git clone https://github.com/tianqixin/runoob-git-test another-runoob-name
Cloning into 'another-runoob-name'...
remote: Enumerating objects: 12, done.
remote: Total 12 (delta 0), reused 0 (delta 0), pack-reused 12
Unpacking objects: 100% (12/12), done.
```



## 提交与更改

Git 的工作就是创建和保存你的项目的快照及与之后的快照进行对比。

下面列出了有关创建与提交你的项目的快照的命令：

### git add (添加命令):

**git add** 命令可将该文件添加到暂存区。

添加一个或多个文件到暂存区：

```
git add [file1] [file2] ...
```

添加指定目录到暂存区，包括子目录：

```
git add [dir]
```

**添加当前目录下的所有文件到暂存区：**

```
git add .
```

以下实例我们添加两个文件：

```
$ touch README                # 创建文件
$ touch hello.php             # 创建文件
$ ls
README        hello.php
$ git status -s
?? README
?? hello.php
$ 
```

![img](https://www.runoob.com/wp-content/uploads/2015/02/B8B4BCDD-158E-4A48-AF22-55CBE0D89F62.jpg)

git status 命令用于查看项目的当前状态。

接下来我们执行 git add 命令来添加文件：

```
$ git add README hello.php 
```

现在我们再执行 git status，就可以看到这两个文件已经加上去了。

```
$ git status -s
A  README
A  hello.php
$ 
```

![img](https://www.runoob.com/wp-content/uploads/2020/08/C87C909B-94F9-496B-B942-1FE9DD464843.jpg)

新项目中，添加所有文件很普遍，我们可以使用 **git add .** 命令来添加当前项目的所有文件。

现在我们修改 README 文件：

```
$ vim README
```

在 README 添加以下内容：**# Runoob Git 测试**，然后保存退出。

再执行一下 git status：

```
$ git status -s
AM README
A  hello.php
```

![img](https://www.runoob.com/wp-content/uploads/2020/08/F3B705BE-7D52-46E7-BF64-EA0EFCC52373.jpg)

**AM** 状态的意思是这个文件在我们将它添加到缓存之后又有改动。改动后我们再执行 **git add .** 命令将其添加到缓存中：

```
$ git add .
$ git status -s
A  README
A  hello.php
```

文件修改后，我们一般都需要进行 git add 操作，从而保存历史版本。