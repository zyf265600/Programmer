from typing import List, Optional


class ListNode:
    def __init__(self, x):
        self.value = x
        self.next = None

def createLinkedList(arr: List[int]) -> Optional[ListNode]:
    if arr is None or len(arr) == 0:
        return None

    head = ListNode(arr[0])
    temp = head

    for n in arr[1:]:
        temp.next = ListNode(n)
        temp = temp.next

    return head

def addToHead(cur_head:ListNode, value:int)->ListNode:
    new_head = ListNode(value)
    new_head.next = cur_head
    return new_head

def addToTail(head:ListNode, value:int):
    temp = head
    while temp.next is not None:
        temp = temp.next
    temp.next = ListNode(value)

def deleteHead(head:ListNode)->ListNode:
    return head.next

def deleteTail(head:ListNode):
    temp = head
    if temp.next is None:
        head = None

    while temp.next.next is not None:
        temp = temp.next

    temp.next = None

def printLinkedList(head:ListNode):
    cur = head
    while cur is not None:
        print(cur.value, end= " -> ")
        cur = cur.next

def printArray(arr:[int]):
    for i in arr:
        print(i, end=", ")

if __name__ == "__main__":
    arr = [0] * 10
    for i in range (10):
        arr[i]=i
    printArray(arr)
    print('\n')

    head = createLinkedList(arr)
    printLinkedList(head)

    head = addToHead(head, -1)
    print('\n')
    printLinkedList(head)

    addToTail(head, 10)
    print('\n')
    printLinkedList(head)

    head = deleteHead(head)
    print('\n')
    printLinkedList(head)

    deleteTail(head)
    print('\n')
    printLinkedList(head)