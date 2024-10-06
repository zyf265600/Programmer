# coding=utf-8

from python_source.list_node import ListNode, init_list

class MergeTwoLists:

    def mergeTwoLists(self, list1, list2):
        phead = ListNode(0)
        p = phead
        while list1 and list2:
            if list1.val <= list2.val:
                p.next = list1
                list1 = list1.next
            else:
                p.next = list2
                list2 = list2.next
            p = p.next

        if list1 is not None:
            p.next = list1
        else:
            p.next = list2
        return phead.next


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 3, 5, 7]
    list = init_list(nums)

    nums2 = [2, 4, 6, 8]
    list2 = init_list(nums2)

    mergeTwoLists = MergeTwoLists()
    node = mergeTwoLists.mergeTwoLists(list, list2)
