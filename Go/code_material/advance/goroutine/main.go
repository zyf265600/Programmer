package main

import (
	"fmt"
	"sync"
	"time"
)

func myGoroutine(name string, wg *sync.WaitGroup) {
	defer wg.Done()

	for i := 0; i < 5; i++ {
		fmt.Printf("myGoroutine %s\n", name)
		time.Sleep(10 * time.Millisecond)
	}
}

func main() {
	var wg sync.WaitGroup

	wg.Add(2)

	go myGoroutine("goroutine1", &wg)
	go myGoroutine("goroutine2", &wg)

	wg.Wait()
}
