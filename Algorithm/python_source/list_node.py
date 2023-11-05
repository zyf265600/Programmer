# coding=utf-8
# leetcode题目使用的定义方式
class ListNode(object):
    """单链表的结点"""

    def __init__(self, x):
        # _item存放数据元素
        self.val = x
        # _next是下一个节点的标识
        self.next = None

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 根据数组值创建一个链表
def init_list(array):
    # 虚拟头结点
    head = ListNode(-1)
    cur = head
    i, high = 1, len(array)
    for i in range(high):
        node = ListNode(array[i])
        cur.next = node
        cur = node
    return head.next


# 打印链表
def print_linked_list(list_node):
    if list_node is None:
        return

    cur = list_node
    while cur:
        print cur.val
        cur = cur.next

