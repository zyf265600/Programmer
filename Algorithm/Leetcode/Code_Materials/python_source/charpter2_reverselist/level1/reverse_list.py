# coding=utf-8
from python_source.list_node import ListNode, init_list, print_linked_list


class ReverseList:

    # 带虚拟头结点的反转
    def reverseList1(self, head):
        if not head or not head.next:  # 如果链表为空，或者只有一个节点
            return head
        ans = ListNode(-1)
        cur = head

        while cur:
            next = cur.next
            cur.next = ans.next
            ans.next = cur
            cur = next
        return ans.next

    # 不带虚拟头结点的反转
    def reverseList2(self, head):
        if not head or not head.next:  # 如果链表为空，或者只有一个节点
            return head
        cur = head.next
        head.next = None
        while cur:
            next = cur.next
            cur.next = head
            head = cur
            cur = next
        return head


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3, 4]
    list = init_list(nums)
    reverseList = ReverseList()
    node = reverseList.reverseList1(list)
    print_linked_list(node)
