# coding=utf-8

from python.unit3_linklist.part2_hot_problem.list_node import init_list, ListNode, print_linked_list


class PlusOne:
    def plusOne(self, head):
        # ans head
        ans = ListNode(0)
        ans.next = head
        not_nine = ans

        # find the rightmost not-nine digit
        while head:
            if head.val != 9:
                not_nine = head
            head = head.next

        not_nine.val += 1
        not_nine = not_nine.next

        while not_nine:
            not_nine.val = 0
            not_nine = not_nine.next

        return ans if ans.val else ans.next


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3]
    list = init_list(nums)
    plusOne = PlusOne()
    node = plusOne.plusOne(list)
    print_linked_list(node)
