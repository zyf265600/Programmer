# coding=utf-8
from python_source.list_node import ListNode, init_list


class MergeInBetween:
    def mergeInBetween(self, list1, a, b, list2):
        dummy = ListNode(0)
        dummy.next = list1
        tmp1 = tmp2 = dummy
        l1, l2 = a, b + 2
        while l1:
            tmp1 = tmp1.next
            l1 -= 1
        while l2:
            tmp2 = tmp2.next
            l2 -= 1
        tmp1.next = list2
        while list2.next:
            list2 = list2.next
        list2.next = tmp2
        return dummy.next


if __name__ == '__main__':
    array1 = [0, 1, 2, 3, 4, 5]
    array2 = [1000000, 1000001, 1000002]
    list1 = init_list(array1)
    list2 = init_list(array2)
    a = 3
    b = 4
    mergeInBetween = MergeInBetween()
    node = mergeInBetween.mergeInBetween(list1, a, b, list2)

