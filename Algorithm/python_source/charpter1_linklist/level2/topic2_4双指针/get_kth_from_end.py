# coding=utf-8

from python_source.list_node import init_list

class GetKthFromEnd:
    def getKthFromEnd(self, head, k):
        former, latter = head, head
        for _ in range(k):
            if not former: return
            former = former.next
        while former:
            former, latter = former.next, latter.next
        return latter


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3, 4, 5, 6]
    list = init_list(nums)
    getKthFromEnd = GetKthFromEnd()
    node = getKthFromEnd.getKthFromEnd(list, 2)
    print node.val
