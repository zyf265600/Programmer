import heapq
from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __lt__(self, other):
        return self.val <  other.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None

        dummy = ListNode(-1)
        cur = dummy

        pq = []

        for i, node in enumerate(lists):
            if node is not None:
                heapq.heappush(pq, (node.val, i, node))

        while pq:
            minVal, i, minNode = heapq.heappop(pq)
            if minNode.next is not None:
                heapq.heappush(pq, (minNode.next.val, i, minNode.next))
            cur.next = minNode
            cur = cur.next

        return dummy.next



# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here