package leetcode_solutions

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func CreateRoot(nums []interface{}) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	root := &TreeNode{Val: nums[0].(int)}
	queue := []*TreeNode{root}
	i := 1
	for i < len(nums) {
		node := queue[0]
		queue = queue[1:]
		if i < len(nums) && nums[i] != nil {
			node.Left = &TreeNode{Val: nums[i].(int)}
			queue = append(queue, node.Left)
		}
		i++
		if i < len(nums) && nums[i] != nil {
			node.Right = &TreeNode{Val: nums[i].(int)}
			queue = append(queue, node.Right)
		}
		i++
	}
	return root
}
