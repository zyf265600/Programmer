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

### Pointer 指针

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

### Struct 结构体

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

### Array 数组

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

### Slice 切片

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

----

### Map 映射

`map` 映射将**键**映射到**值**。

映射map 的零值为 `nil` 。`nil` 映射既没有键，也不能添加键。

`make` 函数会返回给定类型的映射，并将其初始化备用。初始化 = 分配并建立底层数据结构，使 map 从 nil 变为可写状态。

不初始化只声明 map 不可写。

````go
var m map[string]int
m := make(map[string]int)
````

映射的字面量和结构体类似，只不过必须有键名。

````go
package main

import "fmt"

type Vertex struct {
	Lat, Long float64
}

var m = map[string]Vertex{
	"Bell Labs": Vertex{ // 这里的 Vertex 可以省略，会自动推断，只要外层已经把 value 的具体类型写死了，内部复合字面量就可以省略类型名。
		40.68433, -74.39967,
	},
	"Google": Vertex{
		37.42202, -122.08408,
	},
}

func main() {
	fmt.Println(m)
}
````

在映射 `m` 中插入或修改元素：

```
m[key] = elem
```

获取元素：

```
elem = m[key]
```

删除元素：

```
delete(m, key)
```

通过双赋值检测某个键是否存在：

```
elem, ok = m[key]
```

**若 `key` 在 `m` 中，`ok` 为 `true` ；否则，`ok` 为 `false`。**

**若 `key` 不在映射中，则 `elem` 是==该映射元素类型的零值。==**

注：若 `elem` 或 `ok` 还未声明，你可以使用短变量声明：

```
elem, ok := m[key]
```

----

### Function Value 函数值

函数也是值。它们可以像其他值一样传递。

函数值可以用作函数的参数或返回值。

````go
package main

import (
	"fmt"
	"math"
)

func compute(fn func(float64, float64) float64) float64 {
	return fn(3, 4)
}

func main() {
	hypot := func(x, y float64) float64 {
		return math.Sqrt(x*x + y*y)
	}
	fmt.Println(hypot(5, 12))

	fmt.Println(compute(hypot))
	fmt.Println(compute(math.Pow))
}
````

此外，一个重要概念是==**函数闭包 closure**==。

Go 函数可以是一个闭包。闭包是一个函数值，它引用了其函数体之外的变量。 该函数可以访问并赋予其引用的变量值，换句话说，闭包是一个函数值（function value），它捕获（capture）了其外层作用域（outer scope）中的变量。

````go
func counter() func() int {
    x := 0
    // 匿名函数引用了外部变量 x, 这个函数就是一个闭包
    return func() int {
        x++ // 不是复制变量而是直接access变量本身
        return x
    }
}

func main() {
    c := counter()
    fmt.Println(c()) // 1
    fmt.Println(c()) // 2
    fmt.Println(c()) // 3
}
````

这里发生了什么？

- `counter()` 返回一个函数
- 这个函数持有 `x`
- 即使 `counter()` 已经结束
- `x` 仍然存在

为什么变量不会消失？因为：变量被闭包引用，发生了逃逸（escape to heap）。**Go 编译器会把这些变量分配到堆上（heap），而不是栈上（stack）。**



## 常用包

### fmt — 格式化输入输出

```go
fmt.Println("hello")                        // 打印并换行
fmt.Printf("%s is %d\n", "age", 18)        // 格式化打印
fmt.Sprintf("val: %v", x)                  // 返回字符串，不打印
fmt.Errorf("failed: %w", err)              // 创建带包装的 error
fmt.Scan(&x)                               // 从标准输入读取
```

------

### strings — 字符串操作

```go
strings.Contains("hello", "ell")           // 是否包含子串 → true
strings.HasPrefix("hello", "he")           // 前缀匹配 → true
strings.HasSuffix("hello", "lo")           // 后缀匹配 → true
strings.Index("hello", "ll")               // 子串位置 → 2，找不到返回 -1
strings.Count("hello", "l")               // 子串出现次数 → 2
strings.Replace("aabbcc", "b", "X", 1)    // 替换 n 次，-1 为全部
strings.Split("a,b,c", ",")               // 按分隔符切割 → ["a","b","c"]
strings.Join([]string{"a","b"}, "-")      // 合并切片 → "a-b"
strings.TrimSpace("  hi  ")               // 去首尾空格 → "hi"
strings.Trim("##hi##", "#")              // 去首尾指定字符
strings.ToUpper("hi") / ToLower("HI")    // 大小写转换
strings.Fields("a  b  c")                // 按空白符分割（忽略多余空格）
strings.ReplaceAll("aabb", "b", "X")     // 全部替换
strings.Builder                           // 高效字符串拼接
var b strings.Builder
b.WriteString("hello")
b.WriteString(" world")
fmt.Println(b.String()) // "hello world"
```

------

### strconv — 类型转换

```go
strconv.Itoa(42)                           // int → string
strconv.Atoi("42")                         // string → int，返回 (int, error)
strconv.ParseFloat("3.14", 64)            // string → float64
strconv.ParseBool("true")                 // string → bool
strconv.FormatFloat(3.14, 'f', 2, 64)    // float → string，保留2位小数 → "3.14"
strconv.ParseInt("FF", 16, 64)            // 按进制解析，16进制FF → 255
```

------

### os — 操作系统交互

```go
os.ReadFile("a.txt")                       // 读整个文件 → ([]byte, error)
os.WriteFile("b.txt", data, 0644)         // 写整个文件，0644 是权限
os.Open("a.txt")                          // 只读打开，用于 Scanner/Reader
os.Create("a.txt")                        // 创建/截断，用于写入
os.Remove("a.txt")                        // 删除文件
os.Mkdir("dir", 0755)                     // 创建单层目录
os.MkdirAll("a/b/c", 0755)              // 递归创建目录
os.Getenv("HOME")                         // 读环境变量
os.Args                                   // 命令行参数 []string，[0] 是程序名
os.Exit(1)                                // 立即退出，不执行 defer
```

------

### bufio — 带缓冲 I/O

```go
// 逐行读文件（推荐方式）
f, _ := os.Open("file.txt")
defer f.Close()
scanner := bufio.NewScanner(f)
for scanner.Scan() {
    fmt.Println(scanner.Text())  // 每行文本（不含换行符）
}

// 带缓冲写（减少系统调用）
w := bufio.NewWriter(f)
w.WriteString("hello\n")
w.Flush()  // 必须 Flush 才真正写入
```

------

### io — I/O 基础接口

```go
io.ReadAll(resp.Body)                      // 读取全部内容 → ([]byte, error)
io.Copy(dst, src)                          // 流式复制，适合大文件
io.WriteString(w, "hello")               // 向 Writer 写字符串
io.EOF                                    // 读到末尾的标志 error
```

------

### math

```go
math.Abs(-3.5)                            // 绝对值 → 3.5
math.Sqrt(16)                             // 平方根 → 4
math.Pow(2, 10)                           // 幂运算 → 1024
math.Max(3.0, 5.0)                        // 最大值（只支持 float64）
math.Min(3.0, 5.0)                        // 最小值
math.Floor(3.9) / math.Ceil(3.1)         // 向下/向上取整
math.Round(3.5)                           // 四舍五入 → 4
math.Log(math.E)                          // 自然对数 → 1
math.Log2(8) / math.Log10(100)           // 以2/10为底的对数
math.Pi / math.E                          // 常量
math.MaxInt / math.MinInt                 // int 最大/最小值
```

------

### sort

```go
sort.Ints([]int{3,1,2})                   // 原地升序排列
sort.Strings([]string{"b","a"})          // 字符串升序
sort.Float64s([]float64{...})            // float64 升序

// 自定义排序
sort.Slice(s, func(i, j int) bool {
    return s[i].Age < s[j].Age           // 按 Age 升序
})

sort.Search(n, func(i int) bool {        // 二分查找，返回第一个满足条件的下标
    return a[i] >= target
})

sort.IntsAreSorted(a)                    // 判断是否已排序
```

------

### time

```go
time.Now()                                // 当前时间
time.Since(t)                            // 距 t 过了多久 → Duration
time.Until(t)                            // 距 t 还有多久 → Duration
time.Sleep(2 * time.Second)             // 阻塞等待
time.Second / time.Millisecond           // 时间常量

now := time.Now()
now.Format("2006-01-02 15:04:05")       // 格式化（Go 固定用这个基准时间）
now.Year() / Month() / Day()            // 取年月日
now.Add(24 * time.Hour)                 // 加一天
now.Sub(other)                          // 两时间之差 → Duration

time.Parse("2006-01-02", "2024-01-01") // 字符串 → Time
```

> ⚠️ Go 时间格式必须用 `2006-01-02 15:04:05`，不能用 `YYYY-MM-DD`

------

### errors

```go
errors.New("not found")                  // 创建简单 error
fmt.Errorf("query: %w", err)            // 包装 error（可用 errors.Is/As 解包）
errors.Is(err, target)                  // 判断 err 链中是否包含 target
errors.As(err, &target)                 // 从 err 链中提取特定类型的 error
errors.Unwrap(err)                      // 解包一层
var ErrNotFound = errors.New("not found")

err := fmt.Errorf("db: %w", ErrNotFound)
errors.Is(err, ErrNotFound) // true，即使被包装了
```

------

### sync — 并发同步

```go
// Mutex：保护共享数据
var mu sync.Mutex
mu.Lock(); defer mu.Unlock()

// RWMutex：读多写少场景
var rw sync.RWMutex
rw.RLock() / rw.RUnlock()   // 读锁（可并发）
rw.Lock()  / rw.Unlock()    // 写锁（独占）

// WaitGroup：等待一组 goroutine 完成
var wg sync.WaitGroup
wg.Add(1)
go func() { defer wg.Done(); doWork() }()
wg.Wait()

// Once：只执行一次（如单例初始化）
var once sync.Once
once.Do(func() { initDB() })

// Map：并发安全的 map
var m sync.Map
m.Store("key", "val")
v, ok := m.Load("key")
m.Range(func(k, v any) bool { return true }) // 遍历
```

------

### encoding/json

```go
type User struct {
    Name string `json:"name"`
    Age  int    `json:"age,omitempty"` // omitempty：零值时忽略该字段
}

json.Marshal(u)           // struct → JSON bytes
json.Unmarshal(b, &u)    // JSON bytes → struct
json.MarshalIndent(u, "", "  ")  // 带缩进，便于阅读

// 流式（适合大文件/网络）
json.NewEncoder(w).Encode(u)     // 写入 Writer
json.NewDecoder(r).Decode(&u)    // 从 Reader 读取
```

------

### net/http

```go
// 客户端 GET
resp, err := http.Get("https://api.example.com/data")
defer resp.Body.Close()                   // ⚠️ 必须关闭 Body
body, _ := io.ReadAll(resp.Body)

// 客户端 POST JSON
buf := bytes.NewBuffer(jsonData)
resp, _ := http.Post(url, "application/json", buf)

// 服务端
http.HandleFunc("/hello", func(w http.ResponseWriter, r *http.Request) {
    r.Method                              // "GET" / "POST" 等
    r.URL.Query().Get("name")            // 查询参数
    io.ReadAll(r.Body)                   // 读请求体
    w.WriteHeader(http.StatusOK)         // 设置状态码（默认200）
    json.NewEncoder(w).Encode(result)    // 写响应
})
http.ListenAndServe(":8080", nil)
```

------

### log

```go
log.Println("started")                   // 带时间戳打印
log.Printf("val: %v", x)               // 格式化
log.Fatal("crash")                      // 打印后 os.Exit(1)，不执行 defer
log.Panic("oops")                       // 打印后 panic，会执行 defer

// 自定义 logger
logger := log.New(os.Stderr, "[INFO] ", log.LstdFlags)
logger.Println("custom log")
```

------

### regexp

```go
re := regexp.MustCompile(`\d+`)         // 编译正则（失败直接 panic，适合包级变量）
re.MatchString("abc123")               // 是否匹配 → true
re.FindString("abc123def")             // 第一个匹配 → "123"
re.FindAllString("1a2b3", -1)         // 所有匹配，-1 表示全部
re.ReplaceAllString("a1b2", `\d+`, "X") // 替换 → "aXbX"
re.FindStringSubmatch(`(\w+)@(\w+)`)   // 捕获组
```

------

### path/filepath

```go
filepath.Join("a", "b", "c.txt")       // 拼接路径（自动处理分隔符）
filepath.Dir("/a/b/c.txt")             // 目录部分 → "/a/b"
filepath.Base("/a/b/c.txt")            // 文件名部分 → "c.txt"
filepath.Ext("file.go")               // 扩展名 → ".go"
filepath.Abs("./file.txt")            // 转绝对路径
filepath.Walk(".", func(path string, info fs.FileInfo, err error) error {
    fmt.Println(path)
    return nil
})
```



# 方法与接口

## 方法

在 Java 中，方法是Class中的函数。

Go 没有类。不过你可以为类型定义方法。

==方法就是一类带特殊的 **接收者** 参数的函数。普通函数是独立的。方法是绑定在某个类型上的。== 

方法接收者在它自己的参数列表内，位于 `func` 关键字和方法名之间。

在此例中，`Abs` 方法拥有一个名字为 `v`，类型为 `Vertex` 的接收者。

````go
package main

import (
	"fmt"
	"math"
)

type Vertex struct {
	X, Y float64
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
	v := Vertex{3, 4} 
	fmt.Println(v.Abs()) // Abs是v自己的方法
}
````

**Go 把 OOP 拆开：**

- **struct（结构体）负责数据**
- **method（方法）负责行为**

例如：

```go
type Vertex struct {
    X, Y float64
}

func (v Vertex) Abs() float64 { ... }
```

这已经实现了 class 的核心作用：

- 数据 + 行为绑定

但没有 class 的额外负担。

----

### 非结构体类型声明方法

也可以为非结构体类型声明方法。

在此例中，我们看到了一个带 `Abs` 方法的数值类型 `MyFloat`。

你只能为在同一个包中定义的接收者类型声明方法，而不能为其它别的包中定义的类型 （包括 `int` 之类的内置类型）声明方法。

````go
package main

import (
	"fmt"
	"math"
)

type MyFloat float64

func (f MyFloat) Abs() float64 {
	if f < 0 {
		return float64(-f)
	}
	return float64(f)
}

func main() {
	f := MyFloat(-math.Sqrt2)
	fmt.Println(f.Abs())
}
````

----

### 指针类型的接收者

可以为**指针类型的接收者**声明方法。

这意味着对于某类型 `T`，接收者的类型可以用 `*T` 的文法。 （此外，`T` 本身不能是指针，比如不能是 `*int`。）

例如，这里为 `*Vertex` 定义了 `Scale` 方法。

````go
type Vertex struct {
	X, Y float64
}

func (v Vertex) Abs() float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func (v *Vertex) Scale(f float64) {
	v.X = v.X * f
	v.Y = v.Y * f
}

func main() {
	v := Vertex{3, 4}
  // 虽然 v 不是指针，Go 会自动取地址（auto address-taking 自动取址），等价于：
  // (&v).Scale(10)
	v.Scale(10)
	fmt.Println(v.Abs())
}
````

指针接收者的方法可以修改接收者指向的值（如这里的 `Scale` 所示）。 **==由于方法经常需要修改它的接收者，指针接收者比值接收者更常用。==**

核心结论：

- 修改对象 → 用指针接收者（pointer receiver）
- 只读计算 → 用值接收者（value receiver）

----

### 方法与指针重定向

带指针参数的**函数**必须接受一个指针：

```go
var v Vertex
ScaleFunc(v, 5)  // 编译错误！
ScaleFunc(&v, 5) // OK
```

而**接收者为指针的的方法**被调用时，接收者既能是值又能是指针：

```go
var v Vertex
v.Scale(5)  // OK
p := &v
p.Scale(10) // OK
```

对于语句 `v.Scale(5)` 来说，即便 `v` 是一个值而非指针，带指针接收者的方法也能被直接调用。 也就是说，由于 `Scale` 方法有一个指针接收者，为方便起见，Go 会将语句 `v.Scale(5)` 解释为 `(&v).Scale(5)`。

反之也一样：接受一个**值作为参数的函数**必须接受一个指定类型的值：

```go
var v Vertex
fmt.Println(AbsFunc(v))  // OK
fmt.Println(AbsFunc(&v)) // 编译错误！
```

而以值为接收者的方法被调用时，接收者既能为值又能为指针：

```go
var v Vertex
fmt.Println(v.Abs()) // OK
p := &v
fmt.Println(p.Abs()) // OK
```

这种情况下，方法调用 `p.Abs()` 会被解释为 `(*p).Abs()`。

----

### 选择 值 or 指针 作为接收者

使用**指针接收者**的原因有二：

==首先，方法能够修改其接收者指向的值。==

==其次，这样可以避免在每次调用方法时复制该值。若值的类型为大型结构体时，这样会更加高效。==

----

### Go的面向对象编程

Go **没有 class（类）**，它通过：

> struct（结构体） + method（带 receiver 的函数）

来实现类似面向对象的行为。

```go
type MyReader struct{}

func (m MyReader) Read(p []byte) (int, error) {
    return 0, nil
}
```

这里的：(m MyReader) 就是 receiver。**它的含义是：这个函数是 MyReader 类型的方法**

method 是怎么被编译器识别的？

编译器规则非常简单：

只要函数声明形式是：

```go
func (receiver TypeName) MethodName(...) ...
```

这个函数就被绑定到 TypeName。只要在一个package中，并receiver类型一致。

------

# 三、必须和 struct 写在一起吗？

不需要。

Go 没有“类体（class body）”的概念。

你可以这样写：

```go
type MyReader struct{}
```

然后在文件的任何位置：

```go
func (m MyReader) Read(p []byte) (int, error) {
    return 0, nil
}
```

只要：

- 在同一个 package
- receiver 类型一致

就会绑定成功。

------

# 四、可以跨文件吗？

可以。

只要在同一个 package 下：

file1.go

```go
type MyReader struct{}
```

file2.go

```go
func (m MyReader) Read(p []byte) (int, error) {
    return 0, nil
}
```

仍然是合法的。

------

# 五、Go 的 method 本质是什么？

本质上：

Go 的 method 只是：

> 带 receiver 参数的普通函数

例如：

```go
func (m MyReader) Read(p []byte) (int, error)
```

在编译后，本质等价于：

```go
Read(m MyReader, p []byte) (int, error)
```

只是语法糖（syntactic sugar）。

------

# 六、值 receiver vs 指针 receiver

你还可以写：

```go
func (m *MyReader) Read(p []byte) (int, error)
```

这决定：

- method set（方法集合）
- 是否修改原值
- 是否实现接口

这部分是 Go 面向对象的关键机制。

------

# 七、和 Java 的根本区别

Java：

```java
class MyReader {
    int Read(byte[] p) { ... }
}
```

method 在 class 体内部。

Go：

没有 class 体。

method 通过 receiver 绑定。

Java 是：

> nominal typing（名义类型系统）

Go 是：

> structural typing（结构类型系统）

------

# 八、总结

Go 绑定 method 的规则：

1. 使用 receiver 语法
2. 不需要写在 struct 里面
3. 只要同 package 即可
4. 本质是普通函数
5. 编译器通过 receiver 识别方法归属

------

如果你愿意，我可以接着讲：

- method set 是如何决定接口实现的
- 为什么指针 receiver 有时必须用
- interface 和 method set 的匹配规则
- Go 如何模拟 OOP 而不使用 class

这才是你真正会遇到的核心问题。



## 接口

在 Go 语言中，**接口是一种类型**，它定义了一组**方法签名**，但**不包含具体实现**。

你可以理解为：接口 = 行为规范

它描述“一个类型能做什么”，而不是“它是什么”。

````go
type Reader interface {
    Read(p []byte) (n int, err error)
}
````

这表示：

- 任何类型，只要实现了 `Read([]byte) (int, error)` 方法
- 就自动实现（implement）了这个 `Reader` 接口

==注意：**Go 不需要显式声明 implements**==

----

### 



# 泛型



# 并发
