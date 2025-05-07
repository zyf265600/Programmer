from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        node1 = list1
        node2 = list2
        res = ListNode(-1)
        cur = res

        while node1 is not None and node2 is not None:
            if node1.val < node2.val:
                cur.next = node1
                node1 = node1.next
            else:
                cur.next = node2
                node2 = node2.next

            cur = cur.next

        if node1 is None:
            cur.next = node2
        else:
            cur.next = node1

        return res.next
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here
    l1 = ListNode(1)
    l2 = ListNode(2)
    solution.mergeTwoLists(l1, l2)