package main

import "fmt"

// ************************ LinkedList ************************
// ListNode Linked list Node
type ListNode struct {
	Val  int
	Next *ListNode
}

func createLinkedList(arr []int) *ListNode {
	if len(arr) == 0 {
		return nil
	}
	head := &ListNode{Val: arr[0]}
	cur := head
	for i := 1; i < len(arr); i++ {
		cur.Next = &ListNode{Val: arr[i]}
		cur = cur.Next
	}
	return head
}

// ************************ Double LinkedList ************************
type DoublyListNode[T any] struct {
	Val  T
	Next *DoublyListNode[T]
	Prev *DoublyListNode[T]
}

func createDoublyLinkedList[T any](arr []T) *DoublyListNode[T] {
	if len(arr) == 0 {
		return nil
	}
	head := &DoublyListNode[T]{Val: arr[0]}
	cur := head

	// for 循环迭代创建双链表
	for i := 1; i < len(arr); i++ {
		newNode := &DoublyListNode[T]{Val: arr[i]}
		cur.Next = newNode
		newNode.Prev = cur
		cur = cur.Next
	}
	return head
}

func printLinkedListhead(head *ListNode) {
	for p := head; p != nil; p = p.Next {
		fmt.Println("Node Value:", p.Val)
	}
}

func printDoubleLinkedList[T any](head *DoublyListNode[T]) {
	for p := head; p != nil; p = p.Next {
		fmt.Println("Double Linked list Node Value:", p.Val)
	}
}

func main() {
	// ++++++++++++++++++++++++++++++++++++++++++++ Array ++++++++++++++++++++++++++++++++++++++++++++
	//var arr1 [10]int = [10]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} // 冗余
	//var arr2 [10]int                                          // 零值初始化
	//arr3 := [10]int{1, 2, 3, 4}                               // 推荐
	//arr4 := [...]int{1, 2}                                    // 自动推断长度
	//arr5 := [10]int{3: 99}                                    // 指定索引初始化
	//
	//fmt.Println("**************** Array ****************")
	//fmt.Println(arr1[0])
	//fmt.Println(arr2[0])
	//fmt.Println(arr3[0])
	//fmt.Println(arr4[0])
	//fmt.Println(arr5[3])

	// ++++++++++++++++++++++++++++++++++++++++++++ Slice ++++++++++++++++++++++++++++++++++++++++++++
	//slice1 := []int{1, 2}           // slice = (ptr, len, cap)
	//var slice2 = arr1[1:]           // 区间操作 半包[)
	//var slice3 []int                // nil
	//var slice4 = []int{}            // non-nil
	//var slice5 = make([]int, 5, 10) // make([]T, len, cap)
	//var slice6 = [][]int{
	//	{1, 2, 3},
	//	{1, 2, 3},
	//	{1, 2, 3},
	//}
	//slice7 := []int{1, 2, 3}
	//slice7 = append(slice7, 4) // 会返回新的 slice header
	//slice8 := []int{1, 2, 3, 4, 5}
	//slice9 := []int{2, 3, 5, 7, 11, 13}
	//fmt.Println(slice9)
	//slice9 = slice9[:1]
	//fmt.Println(slice9)
	//slice9 = slice9[:4] // 上界为cap大小
	//fmt.Println(slice9)
	//slice9 = slice9[2:] // 舍弃前两个值，len=2 cap=4 [5 7] 因为 cap = 原数组长度 - 当前起始位置。slice 不允许向前访问。
	//fmt.Println(slice9)
	//// copy
	//s10 := []int{1, 2, 3}
	//newS10 := make([]int, len(s10))
	//copy(newS10, s10)   // 创建一个新的 slice，并复制原 slice 的内容。copy 是逐元素拷贝（element-wise copy），不是共享内存。
	//fmt.Println(newS10) // 1 2 3
	//// delete index i=2
	//s11 := []int{1, 2, 3, 4}
	//copy(s11[2:], s11[2+1:])
	//s11 = s11[:len(s11)-1]
	//fmt.Println(s11) // 1 2 4
	//// add new element index i=2
	//s12 := []int{1, 2, 3}
	//s12 = append(s12, 0) // 先要扩容
	//copy(s12[2+1:], s12[2:])
	//s12[2] = 99
	//fmt.Println(s12) // 1 2 99 3

	//fmt.Println("**************** Slice ****************")
	//fmt.Println(slice1)
	//fmt.Println(slice2)
	//fmt.Println(slice3 == nil)
	//fmt.Println(slice4)
	//fmt.Println(slice5)
	//fmt.Println(slice6)
	//fmt.Println(slice7)
	//for i, v := range slice8 {
	//	fmt.Println(i, v) // index, value
	//}

	// ++++++++++++++++++++++++++++++++++++++++++++ Linked list ++++++++++++++++++++++++++++++++++++++++++++
	//listArr := make([]int, 0, 5)
	//listArr = listArr[:3] // len = 1 now
	//listArr[0] = 1
	//listArr[1] = 2
	//listArr[2] = 99
	//
	//head := createLinkedList(listArr)
	//
	//fmt.Println("**************** LinkedList ****************")
	//if head != nil {
	//	for p := head; p != nil; p = p.Next {
	//		fmt.Println("Node: ", p.Val)
	//	}
	//}
	//
	//var newHead *ListNode = &ListNode{-1, head}
	////printLinkedListhead(newHead)
	//tail := newHead
	//for tail.Next != nil {
	//	tail = tail.Next
	//}
	//tail.Next = &ListNode{999, nil}
	////printLinkedListhead(newHead)
	//cur := newHead
	//for i := 0; cur != nil && i < 2; {
	//	cur = cur.Next
	//	i++
	//}
	//if cur != nil {
	//	cur.Next = &ListNode{333, cur.Next}
	//}
	////printLinkedListhead(newHead)
	//cur = newHead
	//for i := 0; cur != nil && i < 2; {
	//	i++
	//	cur = cur.Next
	//}
	//if cur != nil && cur.Next != nil {
	//	cur.Next = cur.Next.Next
	//}
	////printLinkedListhead(newHead)
	//cur = newHead
	//for cur != nil {
	//	if cur.Next == nil {
	//		newHead = nil
	//		break
	//	} else if cur.Next.Next == nil {
	//		cur.Next = nil
	//		break
	//	}
	//	cur = cur.Next
	//}
	//printLinkedListhead(newHead)

	// +++++++++++++++++++++++++++++ Double Linked list ++++++++++++++++++++++++++++++
	//fmt.Println("**************** Double LinkedList ****************")
	//dllArr := [10]int{1, 2, 3, 4, 5, 666, 7, 8, 9, 10}
	//ddHead := createDoublyLinkedList(dllArr[:]) // 基于数组创建一个 slice
	//var ddTail *DoublyListNode[int]
	//for p := ddHead; p != nil; p = p.Next {
	//	ddTail = p
	//}
	////printDoubleLinkedList(ddTail)
	//ddNewHead := &DoublyListNode[int]{-1, nil, nil}
	//ddHead.Prev = ddNewHead
	//ddNewHead.Next = ddHead
	//ddHead = ddNewHead
	////printDoubleLinkedList(ddHead)
	//ddTail.Next = &DoublyListNode[int]{999, nil, nil}
	//ddTail.Next.Prev = ddTail
	//ddTail = ddTail.Next
	////printDoubleLinkedList(ddHead)
	//ddInsertNode := &DoublyListNode[int]{777, nil, nil}
	//ii := 7
	//ddcur := ddHead
	//for i := 0; ddcur != nil && i < ii-1; i++ {
	//	ddcur = ddcur.Next
	//}
	//ddInsertNode.Prev = ddcur
	//ddInsertNode.Next = ddcur.Next
	//ddcur.Next.Prev = ddInsertNode
	//ddcur.Next = ddInsertNode
	////printDoubleLinkedList(ddHead)
	//ddHead = ddHead.Next
	//ddHead.Prev = nil
	////printDoubleLinkedList(ddHead)
	//ddTail = ddTail.Prev
	//ddTail.Next = nil
	////printDoubleLinkedList(ddHead)
	//di := 6
	//ddcur = ddHead
	//for i := 0; i < di-1; i++ {
	//	ddcur = ddcur.Next
	//}
	//ddcur.Next = ddcur.Next.Next
	//ddcur.Next.Prev = ddcur
	//printDoubleLinkedList(ddHead)

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

	// Set
	// Tree
}
