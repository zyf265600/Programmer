# coding=utf-8
from python_source.list_node import init_list


class RemoveElements:
    def removeElements(self, head, val):
        while head and head.val == val:
            head = head.next
        if head is None:
            return head
        node = head
        while node.next:
            if node.next.val == val:
                node.next = node.next.next
            else:
                node = node.next
        return head


if __name__ == '__main__':
    array = [1, 2, 6, 3, 4, 5, 6]
    val = 6
    head = init_list(array)
    removeElements = RemoveElements()
    node = removeElements.removeElements(head, 6)
    print  node
