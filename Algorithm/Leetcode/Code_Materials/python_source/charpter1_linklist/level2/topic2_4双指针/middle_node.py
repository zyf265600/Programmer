# coding=utf-8

from python_source.list_node import init_list

class MiddleNode:
    def middleNode(self, head):
        if head is None:
            return None

        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3, 4, 5, 6]
    list = init_list(nums)
    middleNode = MiddleNode()
    node = middleNode.middleNode(list)
    print node.val
