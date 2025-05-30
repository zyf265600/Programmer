from typing import *

from scipy.linalg.cython_lapack import dsfrk

from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None

        root_value =  preorder[0]
        root = TreeNode(root_value)
        root_inorder_index = inorder.index(root_value)

        root.left = self.buildTree(preorder[1: 1+root_inorder_index], inorder[:root_inorder_index])
        root.right = self.buildTree(preorder[1+root_inorder_index:], inorder[root_inorder_index + 1:])

        return root




# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here