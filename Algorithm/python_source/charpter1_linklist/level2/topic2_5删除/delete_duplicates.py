# coding=utf-8
from python_source.list_node import ListNode, init_list


class DeleteDuplicates:
    # 2.5.3.1 重复元素保留一个
    def deleteDuplicates(self, head):
        if not head:
            return head
        cur = head
        while cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head

    # 2.5.3.2 重复元素都不要
    def deleteDuplicates2(self, head):
        if not head:
            return head

        dummy = ListNode(0, head)
        cur = dummy
        while cur.next and cur.next.next:
            if cur.next.val == cur.next.next.val:
                x = cur.next.val
                while cur.next and cur.next.val == x:
                    cur.next = cur.next.next
            else:
                cur = cur.next

        return dummy.next


if __name__ == '__main__':
    head = [1, 1, 2, 3, 3]
    list = init_list(head)
    deleteDuplicates = DeleteDuplicates()
    node = deleteDuplicates.deleteDuplicates2(list)
    print node
