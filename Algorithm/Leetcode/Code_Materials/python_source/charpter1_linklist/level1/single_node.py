# coding=utf-8
class Node(object):
    """单链表的结点"""
    def __init__(self, item):
        # _item存放数据元素
        self.item = item
        # _next是下一个节点的标识
        self.next = None
