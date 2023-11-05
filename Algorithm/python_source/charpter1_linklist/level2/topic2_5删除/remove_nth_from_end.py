# coding=utf-8

from python_source.list_node import ListNode, init_list, print_linked_list


class RemoveNthFromEnd:
    # 方法1 计算链表长度
    def removeNthFromEnd(self, head, n):
        def getLength(head):
            length = 0
            while head:
                length += 1
                head = head.next
            return length

        dummy = ListNode(0, head)
        length = getLength(head)
        cur = dummy
        for i in range(1, length - n + 1):
            cur = cur.next
        cur.next = cur.next.next
        return dummy.next

    # 方法2 双指针
    def removeNthFromEnd2(self, head, n):
        dummy = ListNode(0, head)
        fast = head
        slow = dummy
        for i in range(n):
            fast = fast.next

        while fast:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next
        return dummy.next


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3, 4, 5]
    list = init_list(nums)
    removeNthFromEnd = RemoveNthFromEnd()
    node = removeNthFromEnd.removeNthFromEnd2(list, 2)
    print_linked_list(node)
