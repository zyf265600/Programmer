from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if root is None:
            return None

        cur = root
        cur.next = None

        while cur.left:
            tmp = cur
            while tmp:
                # 将tmp的左右节点都串联起来
                # 注:外层循环已经判断了当前节点的left不为空
                tmp.left.next = tmp.right
                # 下一个不为空说明上一层已经帮我们完成串联了
                if tmp.next:
                    tmp.right.next = tmp.next.left
                # 继续右边遍历
                tmp = tmp.next
            # 从下一层的最左边开始遍历
            cur = cur.left
        return root
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here