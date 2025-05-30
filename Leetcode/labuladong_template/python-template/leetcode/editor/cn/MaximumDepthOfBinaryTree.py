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
        self.md = 0

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.traverse(root)
        return self.md

    def traverse(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        l_m = self.traverse(root.left)
        r_m = self.traverse(root.right)

        self.md = max(self.md, max(l_m, r_m) + 1)

        return max(l_m, r_m) + 1





    #
    #
    # def __init__(self):
    #     self.d = 0
    #     self.md = float('-inf')
    #
    # def maxDepth(self, root: Optional[TreeNode]) -> int:
    #     if not root:
    #         return 0
    #
    #     self.traverse(root)
    #
    #     return self.md
    #
    #
    # def traverse(self, root: Optional[TreeNode]):
    #     if not root:
    #         return
    #
    #     self.d += 1
    #
    #     if not root.left and not root.right:
    #         self.md = max(self.md, self.d)
    #
    #     self.traverse(root.left)
    #     self.traverse(root.right)
    #
    #     self.d -= 1

    # def maxDepth(self, root: TreeNode) -> int:
    #     if root is None:
    #         return 0
    #
    #     left_depth = self.maxDepth(root.left)
    #     right_depth = self.maxDepth(root.right)
    #
    #     return max(left_depth, right_depth) + 1
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here