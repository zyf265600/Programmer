# Golang 语言基础
本文针对初学者，介绍 Golang 的基本使用，包括控制语句、标准库的常用数据结构等，以便快速上手刷题。
## 标准输出
Golang 的标准输出使用 `fmt` 包中的 `Println` 和 `Printf` 函数，用于在控制台打印内容并换行或格式化输出。
```go
package main

import (
    "fmt"
)

func main() {
    a := 10

    // 输出：10
    fmt.Println(a)

    // 可以串联输出
    // 输出：Hello, World!
    fmt.Println("Hello" + ", " + "World!")

    s := "abc"
    // 输出：abc 10
    fmt.Println(s, a)

    // 格式化输出
    // 输出：abc 10
    fmt.Printf("%s %d\n", s, a)
}
```
## 控制语句
编程语言的控制语句一般都比较简单，最常见的无非就是条件判断和循环，下面简单介绍一下。
### 条件判断 if else
```go
package main

import (
    "fmt"
)

func main() {
    a := 10

    if a > 5 {
        fmt.Println("a > 5")
    } else if a == 5 {
        fmt.Println("a == 5")
    } else {
        fmt.Println("a < 5")
    }
    // 输出：a > 5
}
```
### 循环 for
很多其他语言中有 `for` 和 `while` 两个关键字，但 Golang 中只有 `for` 一个关键字，同时实现了其他语言中 `while` 的功能：
```go
package main

import (
    "fmt"
)

func main() {
    // 输出：0 1 2 3 4 
    for i := 0; i < 5; i++ {
        fmt.Print(i, " ")
    }
    fmt.Println()

    num := 100
    // 输出：100 50 25 12 6 3 1 
    for num > 0 {
        fmt.Print(num, " ")
        num /= 2
    }
    fmt.Println()
}
```
## 基本数据结构
Golang 的标准库提供了多种常用数据结构，如切片（Slice）、链表（List）、映射（Map）等。以下是一些常用数据结构的介绍及其使用方法。
### 动态数组 `Slice`
在 Golang 中，切片（Slice）是动态数组的实现。相比于固定大小的数组，切片可以根据需要动态调整大小。
初始化方法：
```go
package main

import (
	"fmt"
)

func main() {
	// 初始化一个空的切片 nums
	var nums []int

	// 初始化一个大小为 7 的切片 nums，元素值默认都为 0
	nums = make([]int, 7)

	// 初始化一个包含元素 1, 3, 5 的切片 nums
	nums = []int{1, 3, 5}

	// 初始化一个大小为 7 的切片 nums，其值全都为 2
	nums = make([]int, 7)
	for i := range nums {
		nums[i] = 2
	}

	fmt.Println(nums)

	// 初始化一个大小为 3 * 3 的布尔切片 dp，其中的值都初始化为 true
	var dp [][]bool
	dp = make([][]bool, 3)
	for i := 0; i < len(dp); i++ {
		row := make([]bool, 3)
		for j := range row {
			row[j] = true
		}
		dp[i] = row
	}

	fmt.Println(dp)
}
```
其他常用操作：
```go
package main

import (
	"fmt"
)

func main() {
	n := 10
	// 初始化切片，大小为 10，元素值都为 0
	nums := make([]int, n)

	// 输出：false
	fmt.Println(len(nums) == 0)

	// 输出：10
	fmt.Println(len(nums))

	// 在切片尾部插入一个元素 20
	// append 函数会返回一个新的切片，所以需要将返回值重新赋值给 nums
	nums = append(nums, 20)
	// 输出：11
	fmt.Println(len(nums))

	// 得到切片最后一个元素
	// 输出：20
	fmt.Println(nums[len(nums)-1])

	// 删除切片的最后一个元素
	nums = nums[:len(nums)-1]
	// 输出：10
	fmt.Println(len(nums))

	// 可以通过索引直接取值或修改
	nums[0] = 11
	// 输出：11
	fmt.Println(nums[0])

	// 在索引 3 处插入一个元素 99
	// ... 是展开操作符，表示将切片中的元素展开
	nums = append(nums[:3], append([]int{99}, nums[3:]...)...)

	// 删除索引 2 处的元素
	nums = append(nums[:2], nums[3:]...)

	// 交换 nums[0] 和 nums[1]
	nums[0], nums[1] = nums[1], nums[0]

	// 遍历切片
	// 输出：0 11 99 0 0 0 0 0 0 0
	for _, num := range nums {
		fmt.Print(num, " ")
	}
	fmt.Println()
}
```
注意，用 `append` 方法向切片中插入元素时，需要将返回值重新赋值给原切片，因为添加元素的过程中可能触发扩容重新分配内存，所以需要用变量重新接收。
以上就是 Golang 切片（Slice）的常用方法，主要包括通过索引访问元素以及添加、删除元素的方法。在算法题中，切片的这些方法已经足够使用。
### 双链表 `container/list`
Golang 标准库中的 `container/list` 包提供了双向链表的实现。相比于切片，链表在头部和尾部插入和删除元素时性能更好。
常用方法：
```go
package main

import (
    "container/list"
    "fmt"
)

func main() {
    // 初始化链表
    lst := list.New()
    lst.PushBack(1)
    lst.PushBack(2)
    lst.PushBack(3)
    lst.PushBack(4)
    lst.PushBack(5)

    // 检查链表是否为空，输出：false
    fmt.Println(lst.Len() == 0)

    // 获取链表的大小，输出：5
    fmt.Println(lst.Len())

    // 在链表头部插入元素 0
    lst.PushFront(0)
    // 在链表尾部插入元素 6
    lst.PushBack(6)

    // 获取链表头部和尾部元素，输出：0 6
    front := lst.Front().Value.(int)
    back := lst.Back().Value.(int)
    fmt.Println(front, back)

    // 删除链表头部元素
    lst.Remove(lst.Front())
    // 删除链表尾部元素
    lst.Remove(lst.Back())

    // 在链表中插入元素
    // 移动到第三个位置
    third := lst.Front().Next().Next()
    lst.InsertBefore(99, third)

    // 删除链表中某个元素
    second := lst.Front().Next()
    lst.Remove(second)

    // 遍历链表
    // 输出：1 99 3 4 5
    for e := lst.Front(); e != nil; e = e.Next() {
        fmt.Print(e.Value.(int), " ")
    }
    fmt.Println()
}
```
一般来说，当我们想在头部增删元素时会使用 `container/list`，因为它在头部增删元素的效率比切片（数组）高。但当需要频繁通过索引访问元素时，我们会使用切片。
### 队列
在 Golang 中没有专门的队列类型，但可以使用双向链表 `container/list` 来模拟队列的功能，因为链表的头部和尾部插入和删除元素的性能都很好。
```go
package main

import (
    "container/list"
    "fmt"
)

func main() {
    // 初始化一个空的整型队列 q
    q := list.New()

    // 在队尾添加元素
    q.PushBack(10)
    q.PushBack(20)
    q.PushBack(30)

    // 检查队列是否为空，输出：false
    fmt.Println(q.Len() == 0)

    // 获取队列的大小，输出：3
    fmt.Println(q.Len())

    // 获取队列的队头元素
    // 输出：10
    front := q.Front().Value.(int)
    fmt.Println(front)

    // 删除队头元素
    q.Remove(q.Front())

    // 输出新的队头元素：20
    newFront := q.Front().Value.(int)
    fmt.Println(newFront)
}
```
### 栈
栈是一种后进先出（LIFO）的数据结构，Golang 标准库没有单独提供一个栈的类型，但可以使用切片或者双链表来模拟栈的功能，因为切片和双链表在尾部添加和删除元素都比较高效。
下面就以切片为例，展示栈的基本操作：
```go
package main

import (
    "fmt"
)

func main() {
    // 初始化一个空的整型栈 s
    var s []int

    // 向栈顶（切片末尾）添加元素
    s = append(s, 10)
    s = append(s, 20)
    s = append(s, 30)

    // 检查栈是否为空，输出：false
    fmt.Println(len(s) == 0)

    // 获取栈的大小，输出：3
    fmt.Println(len(s))

    // 获取栈顶元素，输出：30
    fmt.Println(s[len(s)-1])

    // 删除栈顶元素
    s = s[:len(s)-1]

    // 输出新的栈顶元素：20
    fmt.Println(s[len(s)-1])
}
```
### 哈希表 `map`
Golang 的内置类型 `map` 提供了哈希表的功能，支持基于键值对（key-value）的存储，具有常数时间复杂度的查找、插入和删除操作。
初始化方法：
```go
package main

import (
    "fmt"
)

func main() {
    // 初始化一个空的哈希表 hashmap
    var hashmap map[int]string
    hashmap = make(map[int]string)

    // 初始化一个包含一些键值对的哈希表 hashmap
    hashmap = map[int]string{
        1: "one",
        2: "two",
        3: "three",
    }

    fmt.Println(hashmap)
}
```
常用方法：
```go
package main

import (
    "fmt"
)

func main() {
    // 初始化哈希表
    hashmap := make(map[int]string)
    hashmap[1] = "one"
    hashmap[2] = "two"
    hashmap[3] = "three"

    // 检查哈希表是否为空，输出：false
    fmt.Println(len(hashmap) == 0)

    // 获取哈希表的大小，输出：3
    fmt.Println(len(hashmap))

    // 查找指定键值是否存在
    // 输出：Key 2 -> two
    if val, exists := hashmap[2]; exists {
        fmt.Println("Key 2 ->", val)
    } else {
        fmt.Println("Key 2 not found.")
    }

    // 获取指定键对应的值，若不存在会返回空字符串
    // 输出：
    fmt.Println(hashmap[4])

    // 插入一个新的键值对
    hashmap[4] = "four"

    // 获取新插入的值，输出：four
    fmt.Println(hashmap[4])

    // 删除键值对
    delete(hashmap, 3)

    // 检查删除后键 3 是否存在
    // 输出：Key 3 not found.
    if val, exists := hashmap[3]; exists {
        fmt.Println("Key 3 ->", val)
    } else {
        fmt.Println("Key 3 not found.")
    }

    // 遍历哈希表
    // 输出（顺序可能不同）：
    // 1 -> one
    // 2 -> two
    // 4 -> four
    for key, value := range hashmap {
        fmt.Printf("%d -> %s\n", key, value)
    }
}
```
### 哈希集合（`map` 的变体）
Golang 没有内置的哈希集合类型，但可以使用哈希表 `map` 来模拟集合，键为元素，值为 `struct{}` 或 `bool`。
```go
package main

import (
	"fmt"
)

func main() {
	// 初始化一个包含一些元素的哈希集合 hashset
	hashset := map[int]struct{}{
		1: {},
		2: {},
		3: {},
		4: {},
	}

	// 检查哈希集合是否为空，输出：false
	fmt.Println(len(hashset) == 0)

	// 获取哈希集合的大小，输出：4
	fmt.Println(len(hashset))

	// 查找指定元素是否存在
	// 输出：Element 3 found.
	if _, exists := hashset[3]; exists {
		fmt.Println("Element 3 found.")
	} else {
		fmt.Println("Element 3 not found.")
	}

	// 插入一个新的元素
	hashset[5] = struct{}{}

	// 删除一个元素
	delete(hashset, 2)
	// 输出：Element 2 not found.
	if _, exists := hashset[2]; exists {
		fmt.Println("Element 2 found.")
	} else {
		fmt.Println("Element 2 not found.")
	}

	// 遍历哈希集合
	// 输出（顺序可能不同）：
	// 1
	// 3
	// 4
	// 5
	for element := range hashset {
		fmt.Println(element)
	}
}
```
一般会推荐使用 `map[int]struct{}` 来模拟哈希集合，因为 `struct{}` 不会占用额外的内存空间，而 `bool` 类型会占用一个字节的内存空间。
## 总结
上面这些基础知识就够你开始刷题了。
当然，Golang 的一些第三方库还提供了很多其他数据结构和实用功能，本文都没有介绍。因为一些高级数据结构会在后面的数据结构章节逐步介绍，而每个结构的 API 也是可以在需要的时候查文档的，没必要一开始就全部记住。
下面我会带你做一些力扣的算法题，让你快速把这些数据结构用起来，同时也熟悉一下刷题系统的使用。