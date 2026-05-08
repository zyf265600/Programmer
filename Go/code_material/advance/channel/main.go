package main

import (
	"fmt"
	"time"
)

type SChannel = chan<- int
type RChannel = <-chan int

func main() {
	var ch = make(chan int) //  创建channel

	go func() {
		var send SChannel = ch
		fmt.Println("send: 100")
		send <- 100
	}()

	go func() {
		var rec RChannel = ch
		num := <-rec
		fmt.Printf("receive: %d", num)
	}()
	time.Sleep(2 * time.Second)
}
