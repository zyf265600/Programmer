package main

import (
	"fmt"
	"testing"
)

func TestArray(t *testing.T) {
	// ++++++++++++++++++++++++++++++++++++++++++++ Array ++++++++++++++++++++++++++++++++++++++++++++
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
}
