package leetcode_solutions

import "testing"

//leetcode submit region begin(Prohibit modification and deletion)

func preorderTraversal(root *TreeNode) []int {
	var res []int
	traverse(root, &res)
	return res
}

func traverse(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	*res = append(*res, root.Val)
	traverse(root.Left, res)
	traverse(root.Right, res)
}

//leetcode submit region end(Prohibit modification and deletion)

func TestBinaryTreePreorderTraversal(t *testing.T) {
	// your test code here
	root := CreateRoot([]interface{}{1, 2, 3, 4, 5, nil, 8, nil, nil, 6, 7, 9})
	result := preorderTraversal(root)
	t.Log(result)
}
