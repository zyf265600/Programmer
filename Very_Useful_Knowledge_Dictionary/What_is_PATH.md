# What Is PATH

## 一、什么是 PATH？

`PATH` 是一个**环境变量**，它告诉操作系统：

> “当我在终端输入一个命令，比如 `python` 或 `javac`，应该去哪里找这个可执行文件？”

它的值是由**一系列目录路径组成的列表**，这些路径之间由冒号（`:`）分隔（在 macOS 和 Linux 上）。

------

示例：查看当前的 PATH

```
echo $PATH
```

输出类似这样：

```
/usr/local/bin:/usr/bin:/bin:/Users/zyf/miniconda3/bin:/opt/homebrew/bin
```

这个意思是：

- 当你输入命令，比如 `python`，系统会依次去这些目录里查找是否有一个可执行文件叫 `python`
- 找到就执行，没找到就报错：`command not found`

------



## 二、为什么要修改 PATH？

你安装了一些工具（如 Miniconda、Checker Framework、Java SDK）后，**它们的执行文件往往不在系统默认路径中**，你必须把它们所在目录加到 PATH 中才能在任何地方调用它们。

### 例子 1：添加 Miniconda 到 PATH

```
export PATH=/Users/zyf/miniconda3/bin:$PATH
```

表示把 Miniconda 的命令优先于系统默认命令。

### 例子 2：添加 Checker Framework 到 PATH

```
export PATH=$CHECKERFRAMEWORK/checker/bin:$PATH
```

使你可以在任何地方运行 `javac -processor nullness` 这种带有 Checker 的命令。

------



## 三、`export PATH=...:$PATH` 是什么意思？

这句命令表示**在当前已有 PATH 的基础上，额外添加一个路径**。

例如：

```
export PATH=/my/tools/bin:$PATH
```

相当于：

```
PATH=/my/tools/bin:/usr/local/bin:/usr/bin:...
```

也就是说你没有替换原来的 PATH，而是在前面加了一个新的目录。

> ✅ **加在前面优先级更高**：如果系统中有两个叫 `python` 的可执行文件，哪个目录先出现，就用哪个。

------



## 四、让 PATH 修改永久生效

在终端里执行 `export PATH=...` 是**临时的**，关闭终端就没了。

要让它永久生效，需要把它写进你的 shell 配置文件：

### macOS (zsh 默认)：

```
nano ~/.zshrc
```

添加一行：

```
export PATH=/your/path:$PATH
```

保存并执行：

```
source ~/.zshrc
```

------



## 总结

| 概念                    | 含义                           |
| ----------------------- | ------------------------------ |
| PATH                    | 告诉系统去哪里找命令的执行文件 |
| `export PATH=...:$PATH` | 在已有路径基础上添加自定义路径 |
| 写入 `~/.zshrc`         | 让路径修改永久生效             |
| 顺序                    | 越靠前的路径优先级越高         |
