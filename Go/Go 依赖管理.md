# Go 依赖管理

## 一、核心思想

Go 使用 **Go Modules（模块机制）** 来管理依赖（dependency）。

本质：

- 每个项目是一个 **module（模块）**
- 依赖通过 `go.mod` + `go.sum` 管理
- 不再依赖 GOPATH



## 二、依赖下载机制

### 1. GOPROXY（代理）

作用：下载依赖的中间层

- 默认会走代理（如官方 proxy）
- 可以配置：

```bash
go env -w GOPROXY=xxx
```

关键点：

- `direct`：直接从源码仓库（GitHub等）拉
- 代理解决：
  - 网络问题
  - 依赖缓存

### 2. GOSUMDB（校验）

作用：**保证依赖安全（checksum 校验）**

- 默认使用官方校验库
- 防止依赖被篡改

可关闭或指定：

```bash
GOSUMDB=off
```

### 3. GOPRIVATE

作用：**私有仓库不走 proxy / 校验**

```bash
GOPRIVATE=github.com/xxx
```



## 三、依赖缓存

依赖下载后会缓存到本地：

- `pkg/mod` → 模块源码
- `pkg/sum` → 校验信息

清理：

```bash
go clean -modcache
```



## 四、go.mod 文件

定义模块和依赖关系：

### 关键字段：

#### 1. module

```go
module xxx
```

- 模块路径（import 路径）

#### 2. go

```go
go 1.17
```

- Go 版本

#### 3. require

```go
require xxx v1.0.0
```

- 依赖 + 版本

#### 4. indirect

- 间接依赖（transitive dependency）

#### 5. replace

```go
replace old => new
```

- 替换依赖（常用于本地开发）

#### 6. exclude

- 排除某版本

#### 7. retract

- 标记某版本不可用（官方修复用）



## 五、版本机制

Go Modules 使用 **语义化版本（SemVer）**：

```
vX.Y.Z
```

特殊点：

- v2+ 需要写在 module path 中（如 `/v2`）
- 无 tag 时会生成 pseudo-version



## 六、常用命令

最核心：

```bash
go mod init      # 初始化模块
go mod tidy      # 自动整理依赖（最常用）
go mod download  # 下载依赖
go mod graph     # 查看依赖图
go mod vendor    # 拷贝到 vendor
go mod verify    # 校验依赖
```

关键认知：

- **日常基本只用：`go mod tidy`**



## 七、go.sum 文件

作用：记录依赖的 **hash 校验值**

格式：

```
module version hash
```

特点：

- 自动生成
- 不需要手动修改
- 用于安全验证



## 八、整体流程

开发流程：

1. 初始化

```bash
go mod init
```

2. 写代码 + import 包
3. 自动下载依赖

```bash
go mod tidy
```

4. 运行程序



## 九、一句话总结

Go 依赖管理本质是：

**使用 Go Modules 通过 go.mod 声明依赖，通过 GOPROXY 下载，通过 go.sum 校验，实现去中心化、可复现、安全的依赖管理体系。**

