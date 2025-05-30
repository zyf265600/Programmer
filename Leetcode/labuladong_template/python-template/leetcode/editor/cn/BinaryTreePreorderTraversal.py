from idlelib.tree import TreeNode
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
    # def __init__(self):
    #     self.res = []
    #
    # def traverse(self, root: Optional[TreeNode]):
    #     if root is None:
    #         return
    #
    #     self.res.append(root.val)
    #     self.traverse(root.left)
    #     self.traverse(root.right)
    #
    # def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    #     self.traverse(root)
    #
    #     return self.res

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []

        if root is None:
            return res

        res.append(root.val)

        res.extend(self.preorderTraversal(root.left))
        res.extend(self.preorderTraversal(root.right))

        return res

# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here