package leetcode_solutions

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func CreateHead(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}
	head := &ListNode{Val: nums[0]}
	cur := head
	for i := 1; i < len(nums); i++ {
		cur.Next = &ListNode{Val: nums[i]}
		cur = cur.Next
	}
	return head
}

func PrintList(l *ListNode) {
	cur := l
	for cur != nil {
		arrow := "->"
		if cur.Next == nil {
			arrow = ""
		}
		fmt.Printf("%d %s", cur.Val, arrow)
		cur = cur.Next
	}
}
