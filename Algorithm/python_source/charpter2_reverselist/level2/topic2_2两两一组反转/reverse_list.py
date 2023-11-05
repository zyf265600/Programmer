# coding=utf-8

from python.unit3_linklist.part2_hot_problem.list_node import init_list, ListNode, print_linked_list


class SwapPairs:
    def swapPairs(self, head):
        dummyHead = ListNode(0)
        dummyHead.next = head
        temp = dummyHead
        while temp.next and temp.next.next:
            node1 = temp.next
            node2 = temp.next.next
            temp.next = node2
            node1.next = node2.next
            node2.next = node1
            temp = node1
        return dummyHead.next


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3, 4, 5]
    list = init_list(nums)
    swapPairs = SwapPairs()
    node = swapPairs.swapPairs(list)
    print_linked_list(node)
