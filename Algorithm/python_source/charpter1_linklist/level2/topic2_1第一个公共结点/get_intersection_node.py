# coding=utf-8
from python_source.list_node import ListNode


class GetIntersectionNode:
    # 方法1，使用集合
    def getIntersectionNode(self, headA, headB):
        s = set()
        p, q = headA, headB
        while p:
            s.add(p)
            p = p.next
        while q:
            if q in s:
                return q
            q = q.next
        return None

    # 方法2，使用栈
    def getIntersectionNode2(self, headA, headB):
        s1, s2 = [], []
        p, q = headA, headB
        while p:
            s1.append(p)
            p = p.next
        while q:
            s2.append(q)
            q = q.next
        ans = None
        i, j = len(s1) - 1, len(s2) - 1
        while i >= 0 and j >= 0 and s1[i] == s2[j]:
            ans = s1[i]
            i, j = i - 1, j - 1
        return ans

    # 方法3，拼接两个字符串
    def getIntersectionNode3(self, headA, headB):
        node1, node2 = headA, headB

        while node1 != node2:
            node1 = node1.next if node1 else headB
            node2 = node2.next if node2 else headA

        return node1

    # 方法4，差和双指针
    def getIntersectionNode4(self, headA, headB):
        s1, s2 = 0, 0
        p, q = headA, headB
        # 计算长度
        while p:
            p = p.next
            s1 += 1
        while q:
            q = q.next
            s2 += 1
        # 长链表先走，但不确定AB谁长，所以有两个循环，但实际上有至少一个循环不会执行
        p, q = headA, headB
        for i in range(s1 - s2):
            p = p.next
        for i in range(s2 - s1):
            q = q.next
        while p and q and p != q:
            p = p.next
            q = q.next
        return p


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    a1 = ListNode("a1")
    a2 = ListNode("a2")
    a1.next = a2

    c1 = ListNode("c1")
    c2 = ListNode("c2")
    c3 = ListNode("c3")
    c1.next = c2
    c2.next = c3

    b1 = ListNode("b1")
    b2 = ListNode("b2")
    b3 = ListNode("b3")
    b1.next = b2
    b2.next = b3

    list1 = a1
    a2.next = c1
    b3.next = c1

    getIntersectionNode = GetIntersectionNode()
    node = getIntersectionNode.getIntersectionNode4(a1, b1)
    if node is not None:
        print node.val
