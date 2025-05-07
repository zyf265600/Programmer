from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head:
            return None

        fast : ListNode = head.next
        slow : ListNode = head

        while fast:
            if fast.val != slow.val:
                slow.next = fast
                slow = slow.next

            fast = fast.next

        slow.next = None # 断开与后面重复元素的连接
        return head
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here