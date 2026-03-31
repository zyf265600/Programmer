package main

import (
	"fmt"
	"testing"
)

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

func TestLinkedList(t *testing.T) {

	//++++++++++++++++++++++++++++++++++++++++++++ Linked list ++++++++++++++++++++++++++++++++++++++++++++
	listArr := make([]int, 0, 5)
	listArr = listArr[:3] // len = 1 now
	listArr[0] = 1
	listArr[1] = 2
	listArr[2] = 99

	head := createLinkedList(listArr)

	fmt.Println("**************** LinkedList ****************")
	if head != nil {
		for p := head; p != nil; p = p.Next {
			fmt.Println("Node: ", p.Val)
		}
	}

	var newHead *ListNode = &ListNode{-1, head}
	//printLinkedListhead(newHead)
	tail := newHead
	for tail.Next != nil {
		tail = tail.Next
	}
	tail.Next = &ListNode{999, nil}
	//printLinkedListhead(newHead)
	cur := newHead
	for i := 0; cur != nil && i < 2; {
		cur = cur.Next
		i++
	}
	if cur != nil {
		cur.Next = &ListNode{333, cur.Next}
	}
	//printLinkedListhead(newHead)
	cur = newHead
	for i := 0; cur != nil && i < 2; {
		i++
		cur = cur.Next
	}
	if cur != nil && cur.Next != nil {
		cur.Next = cur.Next.Next
	}
	//printLinkedListhead(newHead)
	cur = newHead
	for cur != nil {
		if cur.Next == nil {
			newHead = nil
			break
		} else if cur.Next.Next == nil {
			cur.Next = nil
			break
		}
		cur = cur.Next
	}
	printLinkedListhead(newHead)

	//+++++++++++++++++++++++++++++ Double Linked list ++++++++++++++++++++++++++++++
	fmt.Println("**************** Double LinkedList ****************")
	dllArr := [10]int{1, 2, 3, 4, 5, 666, 7, 8, 9, 10}
	ddHead := createDoublyLinkedList(dllArr[:]) // 基于数组创建一个 slice
	var ddTail *DoublyListNode[int]
	for p := ddHead; p != nil; p = p.Next {
		ddTail = p
	}
	//printDoubleLinkedList(ddTail)
	ddNewHead := &DoublyListNode[int]{-1, nil, nil}
	ddHead.Prev = ddNewHead
	ddNewHead.Next = ddHead
	ddHead = ddNewHead
	//printDoubleLinkedList(ddHead)
	ddTail.Next = &DoublyListNode[int]{999, nil, nil}
	ddTail.Next.Prev = ddTail
	ddTail = ddTail.Next
	//printDoubleLinkedList(ddHead)
	ddInsertNode := &DoublyListNode[int]{777, nil, nil}
	ii := 7
	ddcur := ddHead
	for i := 0; ddcur != nil && i < ii-1; i++ {
		ddcur = ddcur.Next
	}
	ddInsertNode.Prev = ddcur
	ddInsertNode.Next = ddcur.Next
	ddcur.Next.Prev = ddInsertNode
	ddcur.Next = ddInsertNode
	//printDoubleLinkedList(ddHead)
	ddHead = ddHead.Next
	ddHead.Prev = nil
	//printDoubleLinkedList(ddHead)
	ddTail = ddTail.Prev
	ddTail.Next = nil
	//printDoubleLinkedList(ddHead)
	di := 6
	ddcur = ddHead
	for i := 0; i < di-1; i++ {
		ddcur = ddcur.Next
	}
	ddcur.Next = ddcur.Next.Next
	ddcur.Next.Prev = ddcur
	printDoubleLinkedList(ddHead)
}
