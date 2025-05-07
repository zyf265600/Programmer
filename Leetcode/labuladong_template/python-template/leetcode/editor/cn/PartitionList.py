from typing import *

from numpy.ma.core import equal

from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        less = ListNode(-1)
        lh = less
        equal_more = ListNode(-1)
        emh = equal_more

        while head:
            if head.val < x:
                lh.next = head
                lh = lh.next
            else:
                emh.next = head
                emh = emh.next

            head = head.next

            # temp = head.next
            # head.next = None
            # head = temp

        emh.next = None # if the last node of head is not larger than x then there is cycle without this line
        lh.next = equal_more.next
        return less.next

# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here
    l1 = ListNode(1)
    l2 = ListNode(2)
    l3 = ListNode(3)
    l3.next = l2
    l2.next = l1
    solution.partition(l3, 2)