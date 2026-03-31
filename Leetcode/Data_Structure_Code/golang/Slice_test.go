package main

import (
	"fmt"
	"testing"
)

func TestSlice(t *testing.T) {

	// ++++++++++++++++++++++++++++++++++++++++++++ Slice ++++++++++++++++++++++++++++++++++++++++++++
	var arr1 [10]int = [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} // 冗余

	slice1 := []int{1, 2}           // slice = (ptr, len, cap)
	var slice2 = arr1[1:]           // 区间操作 半包[)
	var slice3 []int                // nil
	var slice4 = []int{}            // non-nil
	var slice5 = make([]int, 5, 10) // make([]T, len, cap)
	var slice6 = [][]int{
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
	}
	slice7 := []int{1, 2, 3}
	slice7 = append(slice7, 4) // 会返回新的 slice header
	slice8 := []int{1, 2, 3, 4, 5}
	slice9 := []int{2, 3, 5, 7, 11, 13}
	fmt.Println(slice9)
	slice9 = slice9[:1]
	fmt.Println(slice9)
	slice9 = slice9[:4] // 上界为cap大小
	fmt.Println(slice9)
	slice9 = slice9[2:] // 舍弃前两个值，len=2 cap=4 [5 7] 因为 cap = 原数组长度 - 当前起始位置。slice 不允许向前访问。
	fmt.Println(slice9)
	
	// copy
	s10 := []int{1, 2, 3}
	newS10 := make([]int, len(s10))
	copy(newS10, s10)   // 创建一个新的 slice，并复制原 slice 的内容。copy 是逐元素拷贝（element-wise copy），不是共享内存。
	fmt.Println(newS10) // 1 2 3
	// delete index i=2
	s11 := []int{1, 2, 3, 4}
	copy(s11[2:], s11[2+1:])
	s11 = s11[:len(s11)-1]
	fmt.Println(s11) // 1 2 4
	// add new element index i=2
	s12 := []int{1, 2, 3}
	s12 = append(s12, 0) // 先要扩容
	copy(s12[2+1:], s12[2:])
	s12[2] = 99
	fmt.Println(s12) // 1 2 99 3

	fmt.Println("**************** Slice ****************")
	fmt.Println(slice1)
	fmt.Println(slice2)
	fmt.Println(slice3 == nil)
	fmt.Println(slice4)
	fmt.Println(slice5)
	fmt.Println(slice6)
	fmt.Println(slice7)
	for i, v := range slice8 {
		fmt.Println(i, v) // index, value
	}
}
