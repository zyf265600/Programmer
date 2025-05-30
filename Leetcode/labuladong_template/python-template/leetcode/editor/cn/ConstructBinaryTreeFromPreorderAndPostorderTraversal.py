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
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None
        # 注意这个判定，没有下面 +2 会出错
        if len(preorder) == 1:
            return TreeNode(preorder[0])

        root_value = preorder[0]
        root = TreeNode(root_value)

        left_root_value = preorder[1]
        postorder_left_root_value_index = postorder.index(left_root_value)

        root.left = self.constructFromPrePost(preorder[1:1+postorder_left_root_value_index+1], postorder[:postorder_left_root_value_index+1])
        root.right = self.constructFromPrePost(preorder[1+postorder_left_root_value_index+1:], postorder[postorder_left_root_value_index+1:-1])

        return root
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here