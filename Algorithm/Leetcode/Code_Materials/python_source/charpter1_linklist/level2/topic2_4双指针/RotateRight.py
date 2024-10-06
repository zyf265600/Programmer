# coding=utf-8
from python_source.list_node import  init_list, print_linked_list


class RotateRight:
    def rotateRight(self, head, k):
        if head is None or head.next is None:
            return head

        num = 0
        basic_head = head
        while head:
            if head.next is None:
                head.next = basic_head
                num += 1
                break
            num += 1
            head = head.next

        # print(num)
        xx = num - (k % num)
        for i in range(xx):
            if i == (xx - 1):
                flag = basic_head
                basic_head = basic_head.next
                flag.next = None
                break
            basic_head = basic_head.next

        return basic_head


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3, 4, 5]
    rotateRight = RotateRight()
    list = init_list(nums)
    node = rotateRight.rotateRight(list, 2)
    print_linked_list(node)
