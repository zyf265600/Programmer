package goroutine

import (
	"fmt"
	"time"
)

func myGroutine() {
	fmt.Println("myGroutine")
}

func goroutine() {
	go myGroutine()
	fmt.Println("end!!!")
	time.Sleep(2 * time.Second)
}
