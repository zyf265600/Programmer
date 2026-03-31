package main

import "fmt"

func main() {
	var x int64 = -99
	fmt.Println(uint(x))

	var y interface{} = 9.9
	switch v := y.(type) {
	case int:
		fmt.Println("Integer:", v)
	case string:
		fmt.Println("String:", v)
	default:
		fmt.Println("Unknown type")
	}

	fmt.Println("counting")

	for i := 0; i < 2; i++ {
		defer fmt.Println(i)
	}

	fmt.Println("done")
}
