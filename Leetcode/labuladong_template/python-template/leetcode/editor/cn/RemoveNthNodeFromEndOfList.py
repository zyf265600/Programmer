from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast = head

        for _ in range(n):
            if fast.next is None:
                return head.next
            fast = fast.next

        slow = head

        while fast.next is not None:
            fast = fast.next
            slow = slow.next

        temp: ListNode = slow.next
        slow.next = slow.next.next
        temp.next = None

        return head

# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here