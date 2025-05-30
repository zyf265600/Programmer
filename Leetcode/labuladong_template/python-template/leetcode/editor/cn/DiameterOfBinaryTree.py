from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.max_d = 0

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        left_max = self.maxDepth(root.left)
        right_max = self.maxDepth(root.right)

        self.max_d = max(self.max_d, left_max + right_max)

        return max(left_max, right_max) + 1


    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.maxDepth(root)
        return self.max_d
        
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here