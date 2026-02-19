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



## 基本类型 & 类型准换

### 基本类型 

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

### **类型转换**

#### **1. 基本语法**

```go
T(x)
```

将 `x` 显式转换为类型 `T`。
Go 不进行自动类型转换（no implicit conversion）。

#### 2. 数值类型转换

不同数值类型不能直接运算：

```go
var a int = 3
var b int64 = 4
sum := int64(a) + b
```

注意：

- 大转小可能发生截断（truncation）
- 有符号转无符号可能改变数值意义

#### 3. 浮点与整数 (向零截断)

```go
f := 3.9
i := int(f) // 结果 3（向零截断）
```

不会四舍五入。

#### 4. string 与 byte / rune

```go
s := "Hi"
b := []byte(s)   // string → []byte（UTF-8 字节）
r := []rune(s)   // string → []rune（Unicode 码点）

s1 := string(b)  // []byte → string
s2 := string(r)  // []rune → string
```

#### 5. 类型断言（Type Assertion）区别

```go
v.(T)
```

用于 interface，不属于类型转换。


## 作用域

### 一、包级作用域（Package Scope）

定义：
在函数外声明的变量、常量、类型、函数。

特点：

- 整个包内所有文件可见，所有函数都能访问
- 首字母大写则可被其他包访问

示例：

```go
package main

import "fmt"

var globalVar int = 100   // 包级变量

func printGlobal() {
    fmt.Println("globalVar =", globalVar)
}

func main() {
    fmt.Println("main sees:", globalVar)
    printGlobal()
}
```

------

### 二、函数作用域（Function Scope）

定义：
在函数内部声明的变量。

特点：

- 只能在当前函数内访问
- 函数结束后失效

示例：

```go
package main

import "fmt"

func main() {
    x := 10
    fmt.Println("inside main:", x)
}

func other() {
    // fmt.Println(x)  // 编译错误：x 未定义
}
```

------

### 三、块级作用域（Block Scope）

定义：
任意 `{}` 都会形成一个新的作用域。

特点：

- 内层可以访问外层变量
- 外层不能访问内层变量

示例：

```go
package main

import "fmt"

func main() {
    x := 10

    {
        y := 20
        fmt.Println("inside block:", x, y)
    }

    fmt.Println("outside block:", x)

    // fmt.Println(y)  // 编译错误：y 未定义
}
```

------

### 四、语句初始化作用域（Init Scope）

定义：
在 `if / for / switch` 初始化部分声明的变量。

特点：

- 仅在该语句结构内有效
- 语句外不可访问

```go
package main

import "fmt"

func divide(a, b int) (int, error) {
    if b == 0 {
        return 0, fmt.Errorf("divide by zero")
    }
    return a / b, nil
}

func main() {
    if result, err := divide(10, 2); err == nil {
      	// result 和 err 只在 if 结构内部有效
        fmt.Println("result:", result)
    } else {
        fmt.Println("error:", err)
    }

    // fmt.Println(result)  // 编译错误
}
```

------

### 五、变量遮蔽（Shadowing）

示例：

```go
package main

import "fmt"

func main() {
    x := 10
    {
        x := 20
        fmt.Println("inner x:", x)
    }
    fmt.Println("outer x:", x)
}
```

输出：

```
inner x: 20
outer x: 10
```

说明：

- 内部 `x` 是新变量
- 遮蔽了外层 `x`
- 两者互不影响

------

### 六、作用域查找顺序

当访问一个变量时，Go 按以下顺序查找：

1. 当前块
2. 外层块
3. 函数作用域
4. 包级作用域
5. 预声明标识符（如 int、len 等）



## 流程控制语句

### for 循环

Go 只有一种循环结构：`for` 循环。

基本的 `for` 循环由三部分组成，它们用分号隔开：

- 初始化语句：在第一次迭代前执行
- 条件表达式：在每次迭代前求值
- 后置语句：在每次迭代的结尾执行

初始化语句通常为一句短变量声明，该变量声明仅在 `for` 语句的作用域中可见。

**注意**：

- 和 C、Java、JavaScript 之类的语言不同，Go 的 `for` 语句后面的三个构成部分外没有小括号， 大括号 `{ }` 则是必须的。
- 初始化语句和后置语句是可选的。此时你可以去掉分号， for 就变成了 while。

```go
package main

import "fmt"

func main() {
	sum := 0
  
	for i := 0; i < 100; i++ {
		sum += i
	}
	fmt.Println(sum)

  // sum 已经有值了 不需要再次声明
  for ; sum < 1000; {
		sum += sum
	}
	fmt.Println(sum)
  
  // 此时你可以去掉分号，因为 C 的 while 在 Go 中叫做 for
  for sum < 1000 {
		sum += sum
	}
	fmt.Println(sum)
  
  // 如果省略循环条件，该循环就不会结束，因此无限循环可以写得很紧凑。
	for {
	} 
}
```

----

### if 判断

Go 的 `if` 语句与 `for` 循环类似，表达式外无需小括号 `( )`，而大括号 `{ }` 则是必须的。

```go
if [init]; [expression] {
  ...
}
```

和 `for` 一样，`if` 语句可以在条件表达式前执行一个**简短初始化语句**。该语句声明的变量作用域仅在 `if` 和 `else` 之内。

```go
package main

import (
	"fmt"
	"math"
)

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	} else {
		fmt.Printf("%g >= %g\n", v, lim)
	}
	// can't use v here, though
	return lim
}

func main() {
	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 20),
	)
}
```

----

### switch 分支

`switch` 语句是编写一连串 `if - else` 语句的简便方法。**它运行第一个 `case` 值 值==等于==条件表达式的子句。**

```go
switch [init]; [expression] {
    case ...
}
```

Go 的 `switch` 语句类似于 C、C++、Java、JavaScript 和 PHP 中的，不过 Go 只会运行选定的 `case`，而非之后所有的 `case`。 在效果上，Go 的做法相当于这些语言中为每个 `case` 后面自动添加了所需的 `break` 语句。同时，case的表达式是**惰性求值（lazy evaluation）**的，不运行的 case 内容不会被提前计算或者运行。

在 Go 中，除非以 `fallthrough` 语句结束，否则分支会自动终止。 Go 的另一点重要的不同在于 `switch` 的 `case` 无需为常量，且取值不限于整数。

```go
package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Print("Go 运行的系统环境：")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("macOS.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s.\n", os)
	}
}
```

无条件的 `switch` 同 `switch true` 一样。

```go
package main

import (
	"fmt"
	"time"
)

func main() {
	t := time.Now()
	switch { // 等同于 switch true
	case t.Hour() < 12:
		fmt.Println("早上好！")
	case t.Hour() < 17:
		fmt.Println("下午好！")
	default:
		fmt.Println("晚上好！")
	}
}
```

----

### defer 推迟

defer 语句会将函数推迟到外层函数返回之后执行。

推迟调用的函数其参数会立即求值，但直到外层函数返回前该函数都不会被调用。换句话说，defer 的“参数值”在声明那一刻就确定；defer 的“函数执行”在外层函数返回时才发生。

````go
package main

import "fmt"

func main() {
	defer fmt.Println("world")

	fmt.Println("hello")
}
// output hello world
````

推迟调用的函数调用会被压入一个栈中。 当外层函数返回时，被推迟的调用会按照后进先出的顺序调用。

````go
package main

import "fmt"

func main() {
	fmt.Println("counting")

	for i := 0; i < 2; i++ {
		defer fmt.Println(i)
	}

	fmt.Println("done")
}
// output 
// counting
// done
// 1
// 0
````

----

### panic 恐慌

`panic` 用于中止当前函数的正常执行流程。

当发生 panic 时：

- 当前函数立即停止执行
- 开始执行当前函数中所有的 `defer`
- 然后向上返回（函数栈展开）
- 如果一直没有被 recover 捕获，程序最终崩溃

```go
package main

import "fmt"

func main() {
	fmt.Println("start")
	panic("something went wrong")
	fmt.Println("end") // 永远不会执行
}
```

输出：

```
start
panic: something went wrong
...
```

panic 会触发 defer，当 panic 发生时，所有已注册的 defer 都会执行 （函数栈展开），最后执行 panic。

```go
package main

import "fmt"

func f() {
	defer fmt.Println("defer in f")
	panic("boom")
}

func main() {
	defer fmt.Println("defer in main")
	f()
}
```

执行顺序：

1. panic 在 f 中发生
2. 执行 f 的 defer
3. 返回到 main
4. 执行 main 的 defer
5. 程序崩溃

输出：

```
defer in f
defer in main
panic: boom
```

**使用场景**

panic 适用于：

- 不可恢复的错误
- 程序逻辑严重错误
- 初始化阶段错误

----

### recover 恢复

`recover` 用于捕获 panic。关键规则：recover 只能在 panic 展开过程中的 defer 中生效。==**如果在普通代码中调用 recover，或者没有panic在展开，会返回 nil。**==

当 panic 向上展开时：

- 如果某个 defer 中调用了 recover
- recover 会：
  - 停止 panic 继续传播
  - **返回 panic 的值**
  - 程序恢复正常执行，不会崩溃。

```go
package main

import "fmt"

func f() {
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("recovered in f:", r)
		}
	}()

	panic("boom")
	fmt.Println("after panic") // 不会执行
}

func main() {
	f()
	fmt.Println("program continues")
}

// output: 
// recovered in f: boom
// program continues
```

**recover 的限制**

1. 必须在 defer 中

```go
recover()  // 无效
```

2. 必须在 panic 展开过程中调用，如果没有 panic：

```go
defer func() {
	fmt.Println(recover()) // 输出 <nil>
}()
```

**使用场景**

recover 适用于：

- 防止整个程序崩溃
- 服务器框架保护每个请求
- 统一错误处理边界

### panic & recover 实例

**HTTP 服务器防止单个请求崩溃整个进程（最常见）**

在 Web 服务中，如果某个 handler 发生 panic，默认会导致整个进程退出。
生产环境通常会在“请求边界”统一 recover。

```go
package main

import (
	"fmt"
	"log"
	"net/http"
)

func recoverMiddleware(next http.HandlerFunc) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) { // 2

		defer func() { // 3
			if err := recover(); err != nil { // 6
				log.Printf("panic: %v\n", err)
				http.Error(w, "internal server error", http.StatusInternalServerError) // 7
			}
		}()

		next(w, r) // 4
	}
}

func riskyHandler(w http.ResponseWriter, r *http.Request) {
	panic("database nil pointer") // 5
}

func main() {
	http.HandleFunc("/", recoverMiddleware(riskyHandler)) // 1
	http.ListenAndServe(":8080", nil)
}
```

在第七步，客户端看到：

```
HTTP/1.1 500 Internal Server Error
internal server error
```

服务器日志看到：

```
panic: database nil pointer
```

如果没有 recoverMiddleware 会发生什么？

如果你直接：

```
http.HandleFunc("/", riskyHandler)
```

当 panic 发生：

- 整个进程崩溃
- 所有连接断开
- 服务不可用



## 更多类型：结构体，切片和映射

### 指针

Go 拥有指针。指针保存了值的内存地址。

类型 `*T` 是指向 `T` 类型值的指针，其零值为 `nil`。

```
var p *int
```

`&` 操作符会生成一个指向其操作数的指针（取址）。

```
i := 42
p = &i
```

`*` 操作符表示指针指向的底层值（取值/解引用）。

```
fmt.Println(*p) // 通过指针 p 读取 i
*p = 21         // 通过指针 p 设置 i
```

与 C 不同，Go 没有指针运算。

----

### 结构体

一个 结构体（`struct`）就是一组 字段（field）。

结构体字段可通过 `.` 来访问。

结构体字段还可通过结构体指针来访问。

如果我们有一个指向结构体的指针 `p` 那么可以通过 `(*p).X` 来访问其字段 `X`。 **不过这么写太啰嗦了，所以语言也允许我们使用隐式解引用，直接写 `p.X` 就可以。**

```go
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func main() {
	v := Vertex{1, 2}
	p := &v
	p.X = 1e9
	fmt.Println(v)
}
```

使用 `Name:` 语法可以仅列出部分字段（字段名的顺序无关）。

特殊的前缀 `&` 返回一个指向结构体的指针。

```go
package main

import "fmt"

type Vertex struct {
	X, Y int
}

var (
	v1 = Vertex{1, 2}  // 创建一个 Vertex 类型的结构体
	v2 = Vertex{X: 1}  // Y:0 被隐式地赋予零值
	v3 = Vertex{}      // X:0 Y:0
	p  = &Vertex{1, 2} // 创建一个 *Vertex 类型的结构体（指针）
)

func main() {
	fmt.Println(v1, p, v2, v3)
}
```

----

### 数组

类型 `[n]T` 表示一个数组，它拥有 `n` 个类型为 `T` 的值。

表达式

```go
var a [10]int
b := [6]int{2, 3, 5, 7, 11, 13}
```

会将变量 `a` 声明为拥有 10 个整数的数组。

数组的长度是其类型的一部分，因此数组不能改变大小。 这看起来是个限制，不过没关系，Go 拥有更加方便的使用数组的方式。

```go
package main

import "fmt"

func main() {
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a[0], a[1])
	fmt.Println(a)

	primes := [6]int{2, 3, 5, 7, 11, 13}
	fmt.Println(primes)
}

```

----

### 切片

切片为数组元素提供了一种**动态大小的视图。**

数组（array）的长度在编译期固定，而切片（slice）则在运行时提供灵活的访问方式，因此在实际开发中比数组更常用。

#### 一、切片类型

切片的类型表示为：

```go
[]T
```

表示元素类型为 `T` 的切片。

例如：

```go
func main() {
    // 切片字面量 []bool{true, true, false}
    q := []int{2, 3, 5, 7, 11, 13}
    fmt.Println(q)
}
```

这段代码会：

1. 创建一个底层数组
2. 创建一个切片（slice header）指向该数组

#### 二、切片的本质

切片本身并不直接存储元素。

一个切片在底层包含三个部分：

- 指向底层数组的指针（pointer）
- 当前长度（length）就是它所包含的元素个数。
- 容量（capacity）是从它的第一个元素开始数，到其底层数组元素末尾的个数。（从当前切片起始位置到数组末尾的可用空间。）

可以抽象表示为：

```
slice = (ptr, len, cap)
```

==**因此：切片是数组的一种动态视图（dynamic view），而不是独立的数据结构。**==

#### 三、切片的区间操作

切片可以通过区间表达式生成：

```go
a[low:high]
```

其中：

- `low` 为起始下标（包含）
- `high` 为结束下标（不包含）

```go
package main

import "fmt"

func main() {
    primes := [6]int{2, 3, 5, 7, 11, 13}

    var s []int = primes[1:4]
    fmt.Println(s)
}
```

输出：

```
[3 5 7]
```

**在进行切片时，你可以利用它的默认行为来忽略上下界。**

切片下界的默认值为 0，上界则是该切片的长度。

对于数组

```
var a [10]int
```

来说，以下切片表达式和它是等价的：

```
a[0:10]
a[:10]
a[0:]
a[:]
```

#### 四、重要理解

1. 切片不会复制数组元素
2. 修改切片中的元素会影响底层数组
3. 切片只是对数组的一段**引用**

#### 五、数组 & 切片内存结构对比

数组内存

```go
a:
| 1 | 2 | 3 | 4 | 5 |
```

切片内存

```go
s:
ptr --> a[1]
len = 3
cap = 4
```

切片就像数组的引用 切片并不存储任何数据，它只是描述了底层数组中的一段。**==底层仍是同一块数组。==**

````go
a := [5]int{1,2,3,4,5}
s := a[1:4]

s[0] = 100
fmt.Println(a)
// output: [1 100 3 4 5]
````

切片 `s` 的长度和容量可通过表达式 `len(s)` 和 `cap(s)` 来获取。可以通过重新切片来扩展一个切片，给它提供足够的容量。 

```go
package main

import "fmt"

func main() {
	s := []int{2, 3, 5, 7, 11, 13}
	printSlice(s)

	// 截取切片使其长度为 0
	s = s[:0]
	printSlice(s)

	// 扩展其长度
	s = s[:4]
	printSlice(s)

	// 舍弃前两个值
	s = s[2:]
	printSlice(s) // len=2 cap=4 [5 7] 因为 cap = 原数组长度 - 当前起始位置。slice 不允许向前访问。
}

func printSlice(s []int) {
	fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
}
```

#### 六、零值

切片的零值是 `nil`。

nil 切片的长度和容量为 0 且没有底层数组。

```go
package main

import "fmt"

func main() {
	var s []int
	fmt.Println(s, len(s), cap(s))
	if s == nil {
		fmt.Println("nil!")
	}
}
// output: 
// [] 0 0 
// nil!
```

#### 七、用 make 创建切片

切片可以用内置函数 `make` 来创建，这也是你创建动态数组的方式。

**make** 是一个专用的构造函数，仅用于切片、映射和通道这三种内建的引用类型。它会执行复杂初始化并直接返回一个已初始化、立即可用的值 ，而非指针。**对于切片**：make([]T, len, cap) 会分配一个底层数组，并创建一个**切片头**来管理这块数组。

![640](assets/640.jpeg)

`make` 函数会分配一个元素为零值的数组并返回一个引用了它的切片：

```go
a := make([]int, 5)  // len(a)=5
```

要指定它的容量，需向 `make` 传入第三个参数：

```go
package main

import "fmt"

func main() {
	a := make([]int, 5)
	printSlice("a", a)

	b := make([]int, 0, 5)
	printSlice("b", b)

	c := b[:2]
	printSlice("c", c)

	d := c[2:5]
	printSlice("d", d)
}

func printSlice(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v\n",
		s, len(x), cap(x), x)
}
```

输出：

```go
a len=5 cap=5 [0 0 0 0 0]
b len=0 cap=5 []
c len=2 cap=5 [0 0]
d len=3 cap=3 [0 0 0]
```

#### 八、二维切片

切片可以包含任何类型，当然也包括其他切片。

```go
board := [][]string{
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
		[]string{"_", "_", "_"},
}
```

#### 九、向切片追加元素

为切片追加新的元素是种常见的操作，为此 Go 提供了内置的 `append` 函数。内置函数的[文档](https://tour.go-zh.org/pkg/builtin/#append)对该函数有详细的介绍。

```
func append(s []T, vs ...T) []T
```

`append` 的第一个参数 `s` 是一个元素类型为 `T` 的切片，其余类型为 `T` 的值将会追加到该切片的末尾。

`append` 的结果是一个包含原切片所有元素加上新添加元素的切片。

==**当 `s` 的底层数组太小，不足以容纳所有给定的值时，它就会分配一个更大的数组。 返回的切片会指向这个新分配的数组。所以cap在拓展后不一定等于len。对于小cap，双倍拓展，不够再双倍。对于 cap >\= 1024，拓展为 1.25 倍。**==

#### 十、range 遍历

`for` 循环的 `range` 形式可遍历切片或映射。

当使用 `for` 循环遍历切片时，每次迭代都会返回两个值。 第一个值为当前元素的下标，第二个值为该下标所对应元素的一份==**副本**==。

可以将下标或值赋予 `_` 来忽略它。若只需要索引，忽略第二个变量即可。

```go
package main

import "fmt"

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main() {
	for i, v := range pow {
		fmt.Printf("2**%d = %d\n", i, v)
	}
  
  for i, _ := range pow
	for _, value := range pow
  for i := range pow
}
```



## 常用包



# 方法与接口



# 泛型



# 并发
