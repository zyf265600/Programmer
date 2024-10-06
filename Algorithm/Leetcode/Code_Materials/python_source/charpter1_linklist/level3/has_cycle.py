# coding=utf-8
from python_source.list_node import ListNode


class HasCycle:
    # 确定环
    def hasCycle(self, head):
        seen = set()
        while head:
            if head in seen:
                return True
            seen.add(head)
            head = head.next
        return False

    # 确定环的入口
    def detectCycle(self, head):
        fast, slow = head, head
        while True:
            if not (fast and fast.next): return
            fast, slow = fast.next.next, slow.next
            if fast == slow: break
        fast = head
        while fast != slow:
            fast, slow = fast.next, slow.next
        return fast


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    a1 = ListNode(3)
    a2 = ListNode(2)
    a3 = ListNode(0)
    a4 = ListNode(-4)
    a1.next = a2
    a2.next = a3
    a3.next = a4
    # 构造环
    a4.next = a2

    # 判断是否存在环
    # hasCycle = HasCycle()
    # print hasCycle.hasCycle(a1)

    # 确定入口
    hasCycle = HasCycle()
    node = hasCycle.detectCycle(a1)
    print node.val
