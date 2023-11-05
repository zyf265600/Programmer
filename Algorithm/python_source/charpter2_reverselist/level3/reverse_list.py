# coding=utf-8
from python_source.list_node import ListNode, init_list, print_linked_list


class ReverseKGroup:
    # 3.3.1 穿针引线法
    def reverseKGroup(self, head, k):
        dummy = ListNode(0)
        dummy.next = head

        pre, end = dummy, dummy

        while end.next:
            # 取出待翻转的部分
            i = 0
            while i < k and end:
                end = end.next
                i += 1
            if not end: break

            # 断开链表
            startNode = pre.next
            nextNode = end.next
            end.next = None

            # 处理翻转
            pre.next = self.reverse(startNode)
            # startNode 转到翻转这部分节点的最后了

            # 连接断开的链表
            startNode.next = nextNode

            # 挪动以进行下一组处理
            pre = startNode
            end = pre
        return dummy.next

    def reverse(self, head):
        pre = None
        curr = head
        while curr:
            nextNode = curr.next
            curr.next = pre
            pre = curr
            curr = nextNode
        return pre

    # 3.3.2 头插法
    def reverseKGroup2(self, head, k):
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        tail = dummy
        while True:
            count = k
            while count and tail:
                count -= 1
                tail = tail.next
            if not tail: break
            head = pre.next
            while pre.next != tail:
                cur = pre.next  # 获取下一个元素
                # pre与cur.next连接起来,此时cur(孤单)掉了出来
                pre.next = cur.next
                cur.next = tail.next  # 和剩余的链表连接起来
                tail.next = cur  # 插在tail后面
            # 改变 pre tail 的值
            pre = head
            tail = head
        return dummy.next


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 3, 4, 5, 6, 7, 8]
    list = init_list(nums)
    reverseKGroup = ReverseKGroup()
    node = reverseKGroup.reverseKGroup2(list, 3)
    print_linked_list(node)
