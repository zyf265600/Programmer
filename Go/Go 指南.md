# Go指南

# 基础

## 包，变量，与函数

每个 Go 程序都由包构成。

程序从 `main` 包开始运行。

按照约定，包名与导入路径的最后一个元素一致。例如，`"math/rand"` 包中的源码均以 `package rand` 语句开始。

此代码用圆括号将导入的包分成一组，这是推荐的“分组”形式的导入语句。

````go
package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Printf("现在你有了 %g 个问题。\n", math.Sqrt(7))
}
````



## 导出名

在 Go 中，如果一个名字以大写字母开头，那么它就是已导出的。例如，`Pizza` 就是个已导出名，`Pi` 也同样，它导出自 `math` 包。

`pizza` 和 `pi` 并未以大写字母开头，所以它们是未导出的。

在导入一个包时，你只能引用其中已导出的名字。 任何「未导出」的名字在该包外均无法访问。

已统一将**所有标题降一级**（整体“少一号”），**内容不变，仅调整标题层级**，可直接覆盖你原有笔记。



## 声明语法

### 一、为什么 Go 的声明语法“反直觉”

在 C / C++ 中，**类型写在变量名前面**：

```c
int x;
int *p;
```

Go 则**刻意反过来**，把**类型写在名字后面**：

```go
var x int
var p *int
```

这是 Go 的核心设计理念之一：

> **声明的重点是“这个名字是什么”，而不是“这个类型是什么”。**

------

### 二、变量声明（Variable Declarations）

#### 1. 基本变量声明

```go
var a int
var b string
```

**解读方式（从左到右）**：

- 声明一个名字 `a`
- 它的类型是 `int`

也可以用于声明一系列变量。和函数的参数列表一样，类型在最后。

```go
var (
    a int
    b string
    c bool
)
var c, python, java bool
```

------

#### 2. 类型推断

```go
var a = 10
var b = "hello"
var c, python, java = true, false, "no!"
i := 42           // int
f := 3.142        // float64
g := 0.867 + 0.5i // complex128
```

Go 会通过 **类型推断（type inference）** 自动决定类型。

------

#### 3. 短变量声明（最常用）

在函数中，短赋值语句 `:=` 可在隐式确定类型的 `var` 声明中使用。

```go
a := 10
b := "hello"
```

特点：

- 只能在函数内部使用，函数外的每个语句都 **必须** 以关键字开始（`var`、`func` 等），因此 `:=` 结构不能在函数外使用。
- 左侧**至少**有一个**新变量**，没有新变量 → **不能用 `:=`**
- 本质仍然是声明 + 初始化

------

#### 4.零值

没有明确初始化的变量声明会被赋予对应类型的 **零值**。

零值是：

- 数值类型为 `0`，
- 布尔类型为 `false`，
- 字符串为 `""`（空字符串）。

----

#### 5. 类型转换

表达式 `T(v)` 将值 `v` 转换为类型 `T`。

一些数值类型的转换：

```go
var i int = 42
var f float64 = float64(i)
var u uint = uint(f)
```

或者，更加简短的形式：

```go
i := 42
f := float64(i)
u := uint(f)
```

与 C 不同的是，Go 在不同类型的项之间赋值时需要显式转换。试着移除例子中的 `float64` 或 `uint` 的类型转换，看看会发生什么。

------

#### 6. 常量

常量的声明与变量类似，只不过使用 `const` 关键字。

常量可以是字符、字符串、布尔值或数值。

常量不能用 `:=` 语法声明。

````go
const Pi = 3.14
````

------

#### 7. 数值常量

Go 中有一类非常特殊的东西：**无类型常量（untyped constants）**

它们的特点是：

- **没有固定类型**
- **精度是“理论上无限的”**
- **只有在“被使用的上下文中”才会被赋予具体类型**

````go
package main

import "fmt"

const (
	// 将 1 左移 100 位来创建一个非常大的数字
	// 即这个数的二进制是 1 后面跟着 100 个 0
	Big = 1 << 100
	// 再往右移 99 位，即 Small = 1 << 1，或者说 Small = 2
	Small = Big >> 99
)

func needInt(x int) int { return x*10 + 1 }
func needFloat(x float64) float64 {
	return x * 0.1
}

func main() {
	fmt.Println(needInt(Small))
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))
  // 三个都允许转换
  // 但 needInt(Big)不行 2^64 装不下
}
````

------

### 三、指针声明（Pointers）

#### 1. Go 的指针声明方式

```go
var p *int
```

**理解方式**：

> `p` 是一个变量，它的类型是 “指向 int 的指针”

而不是：

> `*p` 是 int

这是 Go 与 C 最大的**心智模型差异**之一。

------

#### 2. 多个变量声明时的可读性优势

```go
var a, b *int
```

在 Go 中这表示：

- `a` 和 `b` 都是 `*int`

在 C 中则容易引起歧义。

------

### 四、函数声明（Function Declarations）

#### 1. 基本函数声明

```go
func add(x int, y int) int {
    return x + y
}
```

**逐段理解**：

- `add` 是函数名
- `(x int, y int)` 是参数列表
- `int` 是返回值类型

------

#### 2. 相同类型参数的简写

```go
func add(x, y int) int
```

含义完全等价，更符合 Go 的简洁风格。

------

#### 3. 多返回值（Go 的重要特性）

```go
func swap(a, b int) (int, int) {
    return b, a
}
```

Go 原生支持多返回值，**无需结构体或指针包装**。

------

#### 4. 带名字的返回值
Go 的返回值可被命名，它们会被视作定义在函数顶部的变量。

返回值的命名应当能反应其含义，它可以作为文档使用。

没有参数的 return 语句会直接返回已命名的返回值，也就是「裸」返回值。

裸返回语句应当仅用在下面这样的短函数中。在长的函数中它们会影响代码的可读性。

````go
func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}
````

------

### 五、数组、切片与类型绑定

#### 1. 数组声明

```go
var a [10]int
```

**理解顺序**：

- `a` 是一个变量
- 它是一个长度为 10 的数组
- 元素类型是 `int`

------

#### 2. 切片声明

```go
var s []int
```

`s` 是一个切片（slice），不是数组。

------

#### 3. 复杂声明依然“从名字出发”

```go
var table map[string][]int
```

解读：

- `table` 是一个变量
- 类型是 map
- key 是 string
- value 是 `[]int`

------

### 六、类型声明（Type Declarations）

#### 1. 自定义类型

```go
type MyInt int
```

这不是别名，而是**新类型**。

------

#### 2. 结构体声明

```go
type Person struct {
    Name string
    Age  int
}
```

------

#### 3. 接口声明

```go
type Reader interface {
    Read(p []byte) (n int, err error)
}
```

-------

### 七、导出规则与声明的关系

在 Go 中：

- **首字母大写 → 导出（exported）**
- **首字母小写 → 未导出**

```go
type Person struct {
    Name string   // 可导出
    age  int      // 包内可见
}
```

这条规则适用于：

- 变量
- 函数
- 类型
- 方法
- 常量

------

### 八、设计哲学总结

Go 声明语法的核心目标只有一个：

> **让声明在复杂情况下依然“线性可读”**

即：

- 从左到右阅读
- 从名字出发
- 类型是对名字的描述，而不是修饰符

这也是为什么 Go 在：指针，函数，复合类型，接口中，声明都保持高度一致。



## 基本类型

Go 的基本类型有

```go
bool

string

int  int8  int16  int32  int64
uint uint8 uint16 uint32 uint64 uintptr

byte // uint8 的别名

rune // int32 的别名
     // 表示一个 Unicode 码位

float32 float64

complex64 complex128
```

本例展示了几种类型的变量。 和导入语句一样，变量声明也可以「分组」成一个代码块。

```go
var (
	ToBe   bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)
```

`int`、`uint` 和 `uintptr` 类型在 32-位系统上通常为 32-位宽，在 64-位系统上则为 64-位宽。当你需要一个整数值时应使用 `int` 类型， 除非你有特殊的理由使用固定大小或无符号的整数类型。



## 流程控制语句

### for 循环

### if 判断

### switch 分支

### defer 推迟



## 更多类型：结构体，切片和映射



# 方法与接口



# 泛型



# 并发
