from typing import *
from leetcode.editor.common.node import *


class BinaryTreePreorderTraversal:
    # leetcode submit region begin(Prohibit modification and deletion)
    # Definition for a binary tree node.
    # class TreeNode:
    #     def __init__(self, val=0, left=None, right=None):
    #         self.val = val
    #         self.left = left
    #         self.right = right
    class Solution:
        res = []

        def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
            self.res = []
            self.traverse(root)
            return self.res

        def traverse(self, root):
            if root is None:
                return
            self.res.append(root.val)
            self.traverse(root.left)
            self.traverse(root.right)
    # leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = BinaryTreePreorderTraversal().Solution()
    # your test code here
    root = TreeNode.create_root([1, 2, 3, 4, 5, None, 8, None, None, 6, 7, 9])
    result = solution.preorderTraversal(root)
    print(result)
    
