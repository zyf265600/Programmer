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
        self.max_d = True

    def traverse(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        if not self.max_d:
            return -1

        l_d = self.traverse(root.left)
        r_d = self.traverse(root.right)

        if abs(r_d - l_d) > 1:
            self.max_d = False

        return max(l_d, r_d) + 1

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.traverse(root)
        return self.max_d
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    root = TreeNode.create_root([1,2,3,4,5,None,6,7,None,None,None,None,8])
    solution.isBalanced(root)
    # your test code here