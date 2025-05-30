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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not inorder:
            return None

        root_value = postorder[-1]
        root =  TreeNode(root_value)
        root_inorder_index = inorder.index(root_value)

        root.left = self.buildTree(inorder[:root_inorder_index], postorder[:root_inorder_index])
        root.right = self.buildTree(inorder[root_inorder_index+1:], postorder[root_inorder_index:-1])

        return root
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here