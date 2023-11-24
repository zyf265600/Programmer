# coding=utf-8
class Node():
    def __init__(self, elem):
        # 双向链表结点
        self.pre = None
        self.elem = elem
        self.next = None
