# 🍺 Homebrew 速查表 (Cheat Sheet)

## 什么是 Homebrew?

**Homebrew** 是 macOS（和 Linux）上的一个 **软件包管理工具**，类似于 Linux 下的 `apt` 或 `yum`。
 它的作用是：

- 自动下载、编译、安装、卸载软件
- 统一管理依赖和路径
- 简化命令行与 GUI 应用的安装

安装 Homebrew 后，你可以用一条命令轻松安装开发工具、库和应用程序。

------

## 🔧 基础命令

### 1. 安装与卸载

```bash
brew install <包名>
```

- 作用：安装指定的软件包
- 示例：`brew install wget`（安装 wget 工具）

```bash
brew uninstall <包名>
```

- 作用：卸载指定的软件包
- 示例：`brew uninstall wget`

------

### 2. 搜索与查看信息

```bash
brew search <关键字>
```

- 作用：搜索可用的软件包
- 示例：`brew search node`

```bash
brew info <包名>
```

- 作用：查看包的详细信息（版本、依赖、安装位置等）
- 示例：`brew info python`

------

### 3. 更新与升级

```bash
brew update
```

- 作用：更新 Homebrew 自身（获取最新的软件包列表）

```bash
brew upgrade
```

- 作用：升级所有已安装的软件包到最新版本

```bash
brew upgrade <包名>
```

- 作用：仅升级指定软件包

------

### 4. 清理与诊断

```bash
brew cleanup
```

- 作用：清理旧版本包和缓存，释放磁盘空间

```bash
brew cleanup -n
```

- 作用：预览会清理哪些内容，但不实际删除

```bash
brew doctor
```

- 作用：检查 Homebrew 的健康状态，诊断可能存在的问题

------

### 5. 查看与管理

```bash
brew list
```

- 作用：列出所有已安装的软件

```bash
brew list <包名>
```

- 作用：查看某个包的安装路径和文件列表

```bash
brew outdated
```

- 作用：列出需要升级的软件包

------

## 🔄 服务管理 (常用于数据库/后台服务)

需要先安装插件：

```bash
brew tap homebrew/services
```

常用命令：

```bash
brew services start <包名>     # 启动服务
brew services stop <包名>      # 停止服务
brew services restart <包名>   # 重启服务
brew services list             # 查看所有服务状态
```

示例：

```bash
brew services start mysql
```

（启动 MySQL 数据库后台服务）

------

## 💻 Cask (GUI 应用管理)

Homebrew 除了命令行软件，也能安装 GUI 应用（Cask 模式）：

```bash
brew install --cask <应用名>
```

- 作用：安装 GUI 应用
- 示例：`brew install --cask google-chrome`

```bash
brew uninstall --cask <应用名>
```

- 作用：卸载 GUI 应用
- 示例：`brew uninstall --cask visual-studio-code`

------

## 📌 小结

- **安装/卸载**：`brew install/uninstall`
- **搜索/信息**：`brew search/info`
- **更新/升级**：`brew update/upgrade`
- **清理/诊断**：`brew cleanup/doctor`
- **服务管理**：`brew services`
- **GUI 应用**：`brew install --cask`

