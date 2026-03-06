# Go 程序初始化与执行

## 一、零值（Zero Value）

当为变量分配存储空间时，无论是通过：

- 变量声明（declaration）
- 调用 `new`
- 创建复合字面量（composite literal）
- 调用 `make`

如果未提供显式初始化表达式，该变量都会被赋予默认值。

这个默认值称为该类型的 **零值（zero value）**。

各类型的零值如下：

- 布尔类型（bool） → `false`
- 数值类型（int / float 等） → `0`
- 字符串（string） → `""`
- 指针（pointer） → `nil`
- 函数（function） → `nil`
- 接口（interface） → `nil`
- 切片（slice） → `nil`
- 通道（channel） → `nil`
- 映射（map） → `nil`

零值初始化是 **递归进行的（recursively applied）**。
例如：若数组元素是结构体，则其字段也会被初始化为对应类型的零值。

等价声明示例：

```go
var i int
var i int = 0
```

示例：

```go
type T struct {
    i    int
    f    float64
    next *T
}

t := new(T)
```

此时：

```
t.i    == 0
t.f    == 0.0
t.next == nil
```

以下声明结果等价：

```go
var t T
```

------

## 二、包初始化（Package Initialization）

在一个包内部，**包级变量（package-level variables）** 的初始化按依赖关系逐步进行。

初始化规则如下：

若某个包级变量尚未初始化，并且：

- 没有初始化表达式
  或
- 初始化表达式不依赖未初始化变量

则该变量被视为“可初始化（ready for initialization）”。

编译器会：

1. 按声明顺序扫描变量
2. 选择第一个“可初始化”的变量
3. 执行初始化
4. 重复上述过程

若最终仍存在未初始化变量，则说明存在初始化循环（initialization cycle），程序非法。

------

### 多变量同时初始化

当多个变量由同一个多值表达式初始化时，它们会在同一步骤中一起初始化：

```go
var x = a
var a, b = f()
```

`a` 和 `b` 会在 `x` 之前一起初始化。

------

### 空标识符

空变量 `_` 在初始化顺序上与普通变量完全相同。

------

### 多文件初始化顺序

若变量分布在多个文件中，声明顺序由编译器接收文件的顺序决定。

为确保构建可复现（reproducible build），建议构建系统按文件名字典序传递文件。

------

### 依赖分析规则

依赖分析仅基于源码中的 **词法引用（lexical references）**，而非运行时值。

示例：

```go
var (
    a = c + b
    b = f()
    c = f()
    d = 3
)

func f() int {
    d++
    return d
}
```

初始化顺序为：

```
d → b → c → a
```

子表达式顺序不影响变量初始化顺序。

------

### 当前包内依赖

依赖分析仅在当前包内进行。

若存在隐藏的数据依赖，则初始化顺序未指定（unspecified）。

示例：

```go
var x = I(T{}).ab()
var _ = sideEffect()
var a = b
var b = 42

type I interface {
    ab() []int
}

type T struct{}

func (T) ab() []int {
    return []int{a, b}
}
```

结果：

- `a` 在 `b` 之后初始化
- `x` 的初始化时机未指定
- 因此 `sideEffect()` 的调用时机也未指定

------

## 三、init 函数

变量也可以通过 `init` 函数完成初始化：

```go
func init() {
    ...
}
```

规则：

- 一个包可以定义多个 `init` 函数
- `init` 不能被显式调用
- 只能由运行时自动执行

包初始化流程：

1. 为所有包级变量赋零值
2. 按源码顺序初始化变量
3. 按源码顺序执行所有 `init` 函数

------

## 四、程序初始化（Program Initialization）

完整程序由：

- 一个未被导入的 `main` 包
- 以及其所有依赖包

组成。

初始化规则：

1. 若一个包有导入，则必须先初始化其导入的包
2. 每个包只初始化一次
3. 导入机制保证无循环依赖

具体过程：

- 将所有包按导入依赖排序
- 每一步选择第一个未初始化且其依赖已完成初始化的包
- 重复直到全部完成

包初始化在 **单个 goroutine 中顺序执行**。

`init` 可以启动新的 goroutine，但初始化过程本身不会并发执行多个 `init`。

------

## 五、程序执行（Program Execution）

一个完整程序必须：

- 包名为 `main`
- 定义函数 `main`
- `main` 无参数、无返回值

```go
func main() {
    ...
}
```

执行流程：

1. 初始化所有包
2. 执行 `main.main()`
3. 当 `main` 返回时，程序立即退出

运行时 **不会等待其他 goroutine 完成**。

------

## 六、核心理解（本质）

- 零值是 Go 的内存安全基础
- 包初始化是静态依赖图驱动的确定性过程
- 初始化顺序由“依赖关系 + 声明顺序”共同决定
- 程序入口仅为 `main.main`
- main 返回即进程终止