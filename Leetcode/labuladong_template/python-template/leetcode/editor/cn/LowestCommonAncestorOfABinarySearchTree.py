from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        value = root.val

        if (p.val < value and q.val < value):
            return self.lowestCommonAncestor(root.left, p, q)
        elif (p.val > value and q.val > value):
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return root

        # if root is None:
        #     return None
        #
        # value = root.val
        #
        # if (p.val <= value and q.val >= value) or (p.val >= value and q.val <= value):
        #     return root
        #
        # left = self.lowestCommonAncestor(root.left, p, q)
        # right = self.lowestCommonAncestor(root.right, p, q)
        #
        # return left if left is not None else right
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here