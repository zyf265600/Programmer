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

**AM 状态的意思是这个文件在我们将它添加到缓存之后又有改动**。改动后我们再执行 **git add .** 命令将其添加到缓存中：

```
$ git add .
$ git status -s
A  README
A  hello.php
```

**文件修改后，我们一般都需要进行 git add 操作，从而保存历史版本。**





### git status (状态查询命令):

git status 命令用于查看在你上次提交之后是否有对文件进行再次修改。

```
$ git status
On branch master

Initial commit

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

    new file:   README
    new file:   hello.php
```

通常我们使用 **-s** 参数来获得简短的输出结果：

```
$ git status -s
AM README
A  hello.php
```

![img](https://www.runoob.com/wp-content/uploads/2020/08/F3B705BE-7D52-46E7-BF64-EA0EFCC52373.jpg)

**AM** 状态的意思是这个文件在我们将它添加到缓存之后又有改动。





### git diff (比较命令):

***git diff 命令比较文件的不同，即比较文件在暂存区和工作区的差异。***

***git diff 命令显示已写入暂存区和已经被修改但尚未写入暂存区文件的区别。***

git diff 有两个主要的应用场景。

- 尚未缓存的改动：**git diff**
- 查看已缓存的改动： **git diff --cached**
- 查看已缓存的与未缓存的所有改动：**git diff HEAD**
- 显示摘要而非整个 diff：**git diff --stat**

显示暂存区和工作区的差异:

```
$ git diff [file]
```

显示暂存区和上一次提交(commit)的差异:

```
$ git diff --cached [file]
或
$ git diff --staged [file]
```

显示两次提交之间的差异:

```
$ git diff [first-branch]...[second-branch]
```

在 hello.php 文件中输入以下内容：

```
<?php
echo '菜鸟教程：www.runoob.com';
?>
```

使用 git status 查看状态：

```
$ git status -s
A  README
AM hello.php
$ git diff
diff --git a/hello.php b/hello.php
index e69de29..69b5711 100644
--- a/hello.php
+++ b/hello.php
@@ -0,0 +1,3 @@
+<?php
+echo '菜鸟教程：www.runoob.com';
+?>
```

***git status 显示你上次提交更新后的更改或者写入缓存的改动， 而 git diff 一行一行地显示这些改动具体是啥。***

接下来我们来查看下 **git diff --cached** 的执行效果：

```
$ git add hello.php
$ git status -s
A  README
A  hello.php
$ git diff --cached
diff --git a/README b/README
new file mode 100644
index 0000000..8f87495
--- /dev/null
+++ b/README
@@ -0,0 +1 @@
+# Runoob Git 测试
diff --git a/hello.php b/hello.php
new file mode 100644
index 0000000..69b5711
--- /dev/null
+++ b/hello.php
@@ -0,0 +1,3 @@
+<?php
+echo '菜鸟教程：www.runoob.com';
+?>
```





### git commit (提交命令):

前面章节我们使用 git add 命令将内容写入暂存区。

***git commit 命令将暂存区内容添加到本地仓库中。***

提交暂存区到本地仓库中:

```
git commit -m [message]
```

[message] 可以是一些备注信息。 ***必须要写***

提交暂存区的指定文件到仓库区：

```
$ git commit [file1] [file2] ... -m [message]
```

**-a** 参数设置修改文件后不需要执行 git add 命令，直接来提交

```
$ git commit -m "comments" -a
```

**设置提交代码时的用户信息**

开始前我们需要先设置提交的用户信息，包括用户名和邮箱：

```
$ git config --global user.name 'runoob'
$ git config --global user.email test@runoob.com
```

如果去掉 --global 参数只对当前仓库有效。

**提交修改**

接下来我们就可以对 hello.php 的所有改动从暂存区内容添加到本地仓库中。

以下实例，我们使用 -m 选项以在命令行中提供提交注释。

```
$ git add hello.php
$ git status -s
A  README
A  hello.php
$ git commit -m '第一次版本提交'
[master (root-commit) d32cf1f] 第一次版本提交
 2 files changed, 4 insertions(+)
 create mode 100644 README
 create mode 100644 hello.php
 
```

现在我们已经记录了快照。如果我们再执行 git status:

```
$ git status
# On branch master
nothing to commit (working directory clean)
```

以上输出说明我们在最近一次提交之后，没有做任何改动，是一个 "working directory clean"，翻译过来就是干净的工作目录。

如果你没有设置 -m 选项，Git 会尝试为你打开一个编辑器以填写提交信息。 如果 Git 在你对它的配置中找不到相关信息，默认会打开 vim。屏幕会像这样：

```
# Please enter the commit message for your changes. Lines starting
# with '#' will be ignored, and an empty message aborts the commit.
# On branch master
# Changes to be committed:
#   (use "git reset HEAD <file>..." to unstage)
#
# modified:   hello.php
#
~
~
".git/COMMIT_EDITMSG" 9L, 257C
```

如果你觉得 git add 提交缓存的流程太过繁琐，Git 也允许你用 -a 选项跳过这一步。命令格式如下：

```
git commit -a
```

我们先修改 hello.php 文件为以下内容：

```
<?php
echo '菜鸟教程：www.runoob.com';
echo '菜鸟教程：www.runoob.com';
?>
```

再执行以下命令：

```
$ git commit -am '修改 hello.php 文件'
[master 71ee2cb] 修改 hello.php 文件
 1 file changed, 1 insertion(+)
```





### git reset (回退命令):

**git reset 命令用于回退版本，可以指定退回某一次提交的版本。**

git reset 命令语法格式如下：

```
git reset [--soft | --mixed | --hard] [HEAD]
```

**--mixed** 为默认，可以不用带该参数，***用于重置暂存区的文件与上一次的提交(commit)保持一致，工作区文件内容保持不变。***

```
git reset  [HEAD] 
```

实例：

```
$ git reset HEAD^            # 回退所有内容到上一个版本  
$ git reset HEAD^ hello.php  # 回退 hello.php 文件的版本到上一个版本  
$ git  reset  052e           # 回退到指定版本
```

**--soft** 参数用于***回退到某个版本***：

```
git reset --soft HEAD
```

实例：

```
$ git reset --soft HEAD~3   # 回退上上上一个版本 
```

**--hard** 参数***撤销工作区中所有未提交的修改内容，将暂存区与工作区都回到上一次版本，并删除之前的所有信息提交：（危险操作）***

```
git reset --hard HEAD
```

实例：

```
$ git reset --hard HEAD~3  # 回退上上上一个版本  
$ git reset –hard bae128  # 回退到某个版本回退点之前的所有信息。 
$ git reset --hard origin/master    # 将本地的状态回退到和远程的一样 
```

**注意：**谨慎使用 –hard 参数，它会删除回退点之前的所有信息。

**HEAD 说明：**

- `HEAD `表示当前版本

- `HEAD^ `上一个版本

- `HEAD^^ `上上一个版本

- `HEAD^^^ `上上上一个版本

  

- 以此类推...

  

可以使用 ～数字表示

- HEAD~0 表示当前版本

- HEAD~1 上一个版本

- HEAD^2 上上一个版本

- HEAD^3 上上上一个版本

- 以此类推...

  

**git reset HEAD**

git reset HEAD 命令用于***取消已缓存的内容***。

我们先改动文件 README 文件，内容如下：

```
# Runoob Git 测试
# 菜鸟教程 
```

hello.php 文件修改为：

```
<?php
echo '菜鸟教程：www.runoob.com';
echo '菜鸟教程：www.runoob.com';
echo '菜鸟教程：www.runoob.com';
?>
```

现在两个文件修改后，都提交到了缓存区，我们现在要取消其中一个的缓存，操作如下：

```
$ git status -s
    M README
    M hello.php
$ git add .
$ git status -s
M  README
M  hello.php
$ git reset HEAD hello.php 
Unstaged changes after reset:
M    hello.php
$ git status -s
M  README
    M hello.php
```

现在你执行 git commit，只会将 README 文件的改动提交，而 hello.php 是没有的。

```
$ git commit -m '修改'
[master f50cfda] 修改
    1 file changed, 1 insertion(+)
$ git status -s
    M hello.php
```

可以看到 hello.php 文件的修改并未提交。

这时我们可以使用以下命令将 hello.php 的修改提交：

```
$ git commit -am '修改 hello.php 文件'
[master 760f74d] 修改 hello.php 文件
    1 file changed, 1 insertion(+)
$ git status
On branch master
nothing to commit, working directory clean
```

**简而言之，执行 git reset HEAD 以取消之前 git add 添加，但不希望包含在下一提交快照中的缓存。**





### git rm (删除文件命令):

***git rm 命令用于删除文件。***

如果只是简单地从工作目录中手工删除文件，运行 **git status** 时就会在 **Changes not staged for commit** 的提示。

git rm 删除文件有以下几种形式：

**1. 将文件从<u>*暂存区*</u>和<u>*工作区*</u>中删除：**

```
git rm <file>
```

以下实例从暂存区和工作区中删除 runoob.txt 文件：

```
git rm runoob.txt 
```

*如果删除之前修改过并且已经放到暂存区域的话，则必须要用强制删除选项 **-f**。*

强行从暂存区和工作区中删除修改后的 runoob.txt 文件：

```
git rm -f runoob.txt 
```

**如果想把文件只从暂存区域移除，但仍然希望保留在当前工作目录中**，换句话说，仅是从跟踪清单中删除，使用 **--cached** 选项即可：

```
git rm --cached <file>
```

以下实例从暂存区中删除 runoob.txt 文件：

```
git rm --cached runoob.txt
```

**实例**

删除 hello.php 文件：

```
$ git rm hello.php 
rm 'hello.php'
$ ls
README
```

文件从暂存区域移除，但工作区保留：

```
$ git rm --cached README 
rm 'README'
$ ls
README
```

可以递归删除，即如果后面跟的是一个目录做为参数，则会递归删除整个目录中的所有子目录和文件：

```
git rm –r * 
```

**进入某个目录中，执行此语句，会删除该目录下的所有文件和子目录。**





### git mv (移动或重命名命令):

git mv 命令用于移动或重命名一个文件、目录或软连接。**（前旧后新）**

```
git mv [file] [newfile]
```

如果新文件名已经存在，但还是要重命名它，可以使用 **-f** 参数：

```
git mv -f [file] [newfile]
```

我们可以添加一个 README 文件（如果没有的话）：

```
$ git add README 
```

然后对其重命名:

```
$ git mv README  README.md
$ ls
README.md
```





## 提交日志

Git 提交历史一般常用两个命令：

- **git log** - 查看历史提交记录。
- **git blame <file>** - 以列表形式查看指定文件的历史修改记录。



### git log (回溯历史命令):

在使用 Git 提交了若干更新之后，又或者克隆了某个项目，想回顾下提交历史，我们可以使用 **git log** 命令查看。

针对我们前一章节的操作，使用 **git log** 命令列出历史提交记录如下：

```
$ git log
commit d5e9fc2c811e0ca2b2d28506ef7dc14171a207d9 (HEAD -> master)
Merge: c68142b 7774248
Author: runoob <test@runoob.com>
Date:   Fri May 3 15:55:58 2019 +0800

    Merge branch 'change_site'

commit c68142b562c260c3071754623b08e2657b4c6d5b
Author: runoob <test@runoob.com>
Date:   Fri May 3 15:52:12 2019 +0800

    修改代码

commit 777424832e714cf65d3be79b50a4717aea51ab69 (change_site)
Author: runoob <test@runoob.com>
Date:   Fri May 3 15:49:26 2019 +0800

    changed the runoob.php

commit c1501a244676ff55e7cccac1ecac0e18cbf6cb00
Author: runoob <test@runoob.com>
Date:   Fri May 3 15:35:32 2019 +0800
```

我们可以用 --oneline 选项来查看历史记录的简洁的版本。



- 

- 