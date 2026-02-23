package main

import "fmt"

func main() {
	// Array
	var arr1 [10]int = [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} // 冗余
	var arr2 [10]int                                          // 零值初始化
	arr3 := [10]int{1, 2, 3, 4}                               // 推荐
	arr4 := [...]int{1, 2}                                    // 自动推断长度
	arr5 := [10]int{3: 99}                                    // 指定索引初始化

	fmt.Println("**************** Array ****************")
	fmt.Println(arr1[0])
	fmt.Println(arr2[0])
	fmt.Println(arr3[0])
	fmt.Println(arr4[0])
	fmt.Println(arr5[3])

	// Slice
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

	// Linked list

	// Map
	// Set
	// Tree
}
