#
# @lc app=leetcode.cn id=104 lang=python3
# @lcpr version=30008
#
# [104] 二叉树的最大深度
#


import sys
import os

sys.path.append(os.path.join(os.path.dirname(__file__), '..'))

from typing import *
from common.node import *

class MaximumDepthOfBinaryTree:
    # @lc code=start
    # Definition for a binary tree node.
    # class TreeNode:
    #     def __init__(self, val=0, left=None, right=None):
    #         self.val = val
    #         self.left = left
    #         self.right = right
    class Solution:
        def maxDepth(self, root: Optional[TreeNode]) -> int:
            
    # @lc code=end

if __name__ == '__main__':
    solution = MaximumDepthOfBinaryTree().Solution()
    # your test code here



#
# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [1,null,2]\n
# @lcpr case=end

#

