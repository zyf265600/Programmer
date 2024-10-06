# coding=utf-8
from python_source.charpter1_linklist.level1.Node import Node


class DoubleLinkList:
    def __init__(self, node=None):
        self.__head = node

    def is_empty(self):
        # 链表是否为空
        if self.__head is None:
            return True
        else:
            return False

    def length(self):
        # 链表长度
        if self.is_empty():
            return 0
        count = 0
        cur = self.__head
        while cur is not None:
            count += 1
            cur = cur.next
        return count

    def travel(self):
        # 遍历整个链表
        if self.is_empty():
            return
        cur = self.__head
        while cur is not None:
            print(cur.elem)
            cur = cur.next

    def add(self, item):
        # 链表头部添加元素
        node = Node(item)
        if self.is_empty():  # 原本是空链表的就让头指针直接指向这个新添加的元素结点
            self.__head = node
        else:  # 链表不为空时
            node.next = self.__head  # 新结点的next指针指向头指针所指的结点
            self.__head.pre = node  # 再将头指针结点的pre指针指向新结点的next
            self.__head = node  # 最后修改头指针指向新结点

    def append(self, item):
        # 链表尾部添加元素
        # 创建新结点
        node = Node(item)
        # 是空链表就把头节点指向这个节点
        if self.is_empty():
            self.__head = node
        else:
            cur = self.__head
            while cur.next is not None:  # 循环找到尾部结点的指向，当退出循环时指针已指向最后一个结点
                cur = cur.next
            cur.next = node  # 将尾部结点的next指向新结点
            node.pre = cur

    def modify(self, pos, item):
        """修改指定位置的元素"""
        # 当指定的位置pos小于等于0时，则修改头部元素
        if pos <= 0:
            self.__head.elem = item
        # 当pos大于等于链表总长度时，则修改尾部元素
        elif pos >= self.length():
            tail = self.__head
            # 循环让指针指向尾部元素
            while tail.next is not None:
                tail = tail.next
            tail.elem = item  # 修改尾部元素
        else:
            count = 0
            tail = self.__head
            # 循环指针找到指定的位置
            while count < pos:  # 1.当不满足条件退出循环时，说明指针已经指向了给定的pos位置
                tail = tail.next
                count += 1
            tail.elem = item  # 2.将pos位置的元素修改

    def insert(self, pos, item):
        # 位置pos在第一个元素之前，则在头部插入
        if pos <= 0:
            self.add(item)
            # 位置pos大于总长度，则在尾部插入
        elif pos > self.length():
            self.append(item)
        else:
            # 指定位置添加元素
            # 创建新结点
            node = Node(item)
            count = 0
            cur = self.__head  # 当时指针
            while count < (pos - 1):  # 循环找到指向pos位置结点的指针
                count += 1
                cur = cur.next
            # 当上面退出循环时，说明cur已经指向了pos的位置
            # 所以接下来修改四个指针的指向来实现插入元素
            cur.next.pre = node  # 1.将cur的下一结点的pre指向新结点next
            node.next = cur.next  # 2.将新结点的next指向cur的下一结点
            cur.next = node  # 3.将cur的next指向新结点
            node.pre = cur  # 4.将新结点的pre指向cur的next

    def remove(self, item):
        # 删除节点
        cur = self.__head  # cur当前指针
        forword = None  # 前一个指针
        # 遍历链表当时指针
        while cur is not None:
            # 如果找到了要删除的元素
            if cur.elem == item:
                # 要删除的元素刚好是头部元素，就把头指针指向当前的下一个结点
                if cur == self.__head:
                    self.__head = cur.next
                    self.__head.pre = None
                else:
                    forword.next = cur.next
                    cur.next.pre = forword
                return
            else:
                forword = cur
                cur = cur.next

    def search(self, item):
        # 查找节点是否存在
        cur = self.__head
        while cur.next is not None:
            # 找到了返回True,未找到指向下一个继续遍历
            if cur.elem == item:
                return True
            cur = cur.next
        # 查找的元素在最后一个，遍历后指向最后一个，但是没有进入循环，所以需要在循环体外判断一次
        if cur.elem == item:
            return True
        return False


if __name__ == '__main__':
    ll = DoubleLinkList()

    ll.append(1)
    ll.insert(2, 2)
    ll.append(3)
    ll.append(5)
    ll.remove(2)
    ll.search(2)

    ll.travel()
    ll.add(10)
    ll.travel()

    print('append')
    ll.append(13)
    ll.travel()

    print('insert')
    ll.insert(1, 33)
    ll.travel()

    print('remove')
    ll.remove(10)
    ll.travel()

    print('modify')
    ll.modify(2, 100)
    ll.travel()

    print(ll.search(9))
