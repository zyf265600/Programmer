from collections import deque
from typing import *

from numpy.f2py.crackfortran import traverse

from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # def minDepth(self, root: Optional[TreeNode]) -> int:
    #     if root is None:
    #         return 0
    #
    #     d = 1
    #     q = deque()
    #     q.append(root)
    #
    #     while q:
    #         sz = len(q)
    #
    #         for i in range(sz):
    #             cur: TreeNode = q.popleft()
    #             if cur.left is None and cur.right is None:
    #                 return d
    #             if cur.left is not None:
    #                 q.append(cur.left)
    #             if cur.right is not None:
    #                 q.append(cur.right)
    #         d+=1

##################################################################
    # def __init__(self):
    #     self.min = float('inf')
    #     self.cur = 0
    #
    # def traverse(self, root: Optional[TreeNode]):
    #     if root is None:
    #         return
    #
    #     self.cur += 1
    #
    #     if root.left is None and root.right is None:
    #         self.min = min(self.min, self.cur)
    #     self.traverse(root.left)
    #     self.traverse(root.right)
    #
    #     self.cur -= 1
    #
    #
    # def minDepth(self, root: Optional[TreeNode]) -> int:
    #     if root is None:
    #         return 0
    #
    #     self.traverse(root)
    #
    #     return self.min



# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here