# Ruby 学习笔记

## 第一部分 rbenv 的介绍

### 1. 概述

**rbenv** 是一种 Ruby 版本管理工具。
 它允许在同一台机器上安装、切换和管理多个 Ruby 版本，而不会影响系统自带的 Ruby。

在实际开发中，不同项目可能依赖于不同的 Ruby 版本（例如某些 Rails 项目需要 Ruby 3.x，而另一些可能使用 2.7.x）。rbenv 的核心作用在于实现 **版本切换与隔离**，确保每个项目能够使用其所需的 Ruby 环境。

------

### 2. 核心机制

1. **Shims（垫片）**
   - 当运行 `ruby`、`gem`、`rails` 等命令时，实际执行的是 `~/.rbenv/shims/` 目录下的脚本。
   - 这些脚本会检测当前 rbenv 的配置，并将调用转发到对应版本的 Ruby 可执行文件。
   - 借助这一机制，不同项目能够共存且使用不同的 Ruby 版本。
2. **版本选择优先级**
    rbenv 按照以下顺序确定 Ruby 的版本：
   1. `RBENV_VERSION` 环境变量（临时设置）
   2. 项目目录下的 `.ruby-version` 文件（通过 `rbenv local` 设置）
   3. 全局默认版本（通过 `rbenv global` 设置）
   4. 系统自带 Ruby（例如 macOS 的 `/usr/bin/ruby`）

------

### 3. 常用命令

- **安装 Ruby**

  ```bash
  rbenv install 3.3.1
  ```

  安装 Ruby 3.3.1（依赖 `ruby-build` 插件）。

- **查看已安装的版本**

  ```bash
  rbenv versions
  ```

- **查看当前使用的版本**

  ```bash
  rbenv version
  ```

- **设置全局默认版本**

  ```bash
  rbenv global 3.3.1
  ```

  设置全局默认 Ruby 版本。

- **设置项目本地版本**

  ```bash
  rbenv local 3.2.2
  ```

  在当前目录生成 `.ruby-version` 文件；进入该目录时会自动切换至 3.2.2。

- **临时切换版本（仅在当前终端会话中生效）**

  ```bash
  rbenv shell 3.1.0
  ```

- **重新生成 shims**

  ```bash
  rbenv rehash
  ```

  更新 shim 文件，确保新安装的命令可被识别。

------

### 4. 相关目录

- `~/.rbenv/versions/`
   存放所有已安装的 Ruby 版本。
- `~/.rbenv/shims/`
   存放 shim 文件，用于拦截并转发 `ruby`、`gem`、`rails` 等命令。
- `~/.rbenv/version`
   记录全局默认 Ruby 版本号（由 `rbenv global` 写入）。

------

### 5. 总结

rbenv 的核心功能是 **Ruby 版本的切换与隔离**。
 常见操作可归纳为：

- 安装新版本：`rbenv install`
- 设置全局默认版本：`rbenv global`
- 设置项目本地版本：`rbenv local`
- 临时切换版本：`rbenv shell`

