package main

import (
	"fmt"
	"testing"
)

func TestMap(t *testing.T) {
	// ++++++++++++++++++++++++++++++++++++++++++++ Map ++++++++++++++++++++++++++++++++++++++++++++
	fmt.Println("**************** Map ****************")
	var m1 map[string]int          // m1 == nil 可以读 m["a"] -> 0，不能写 m["a"]=1 -> panic
	m1 = make(map[string]int, 100) // 做了三件事：1 创建 hmap 结构 2 分配 bucket 数组 3 初始化哈希元数据
	m2 := map[string]int{"abc": 1}
	m1["a"] = 999           // 如果 key 存在 → 覆盖; 如果 key 不存在 → 插入
	fmt.Println(m2["abc"])  // 如果 key 不存在 → 返回 value 类型的零值 1
	fmt.Println(m2["abcd"]) // 如果 key 不存在 → 返回 value 类型的零值 0
	delete(m2, "abc")       // 删除不存在的 key 不会 panic
	fmt.Println(m2["abc"])  // 被删return 0
	val, ok := m1["a"]
	fmt.Println(val, ok) // ok == true → key 存在
	val, ok = m2["abc"]
	fmt.Println(val, ok) // ok == false → key 不存在; v 是零值
	m1["b"] = 99
	m1["c"] = 9
	fmt.Println("-- for loop --")
	for k, v := range m1 { // 遍历顺序是随机的（non-deterministic）
		fmt.Println(k, v)
	}
}
