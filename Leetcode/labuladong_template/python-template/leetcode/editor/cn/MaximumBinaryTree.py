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
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        max_value = max(nums)
        max_index = nums.index(max_value)

        left_side = nums[:max_index]
        right_side = nums[max_index + 1: ]

        root = TreeNode(max_value)

        root.left = self.constructMaximumBinaryTree(left_side)
        root.right = self.constructMaximumBinaryTree(right_side)

        return root

# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here