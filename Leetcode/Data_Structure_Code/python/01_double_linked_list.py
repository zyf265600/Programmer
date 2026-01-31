from typing import List, Optional


class DoublyListNode:
    def __init__(self, x):
        self.value = x
        self.prev = None
        self.next = None


def createDoublyLinkedList(arr: List[int]) -> Optional[DoublyListNode]:
    if arr is None or len(arr) == 0:
        return None

    head = DoublyListNode(arr[0])
    cur = head

    for n in arr[1:]:
        temp = cur
        cur.next = DoublyListNode(n)
        cur = cur.next
        cur.prev = temp

    return head


def findTail(head: DoublyListNode) -> DoublyListNode:
    temp = head
    while temp.next is not None:
        temp = temp.next
    return temp


def addToHead(cur_head: DoublyListNode, value: int) -> DoublyListNode:
    new_head = DoublyListNode(value)
    new_head.next = cur_head
    cur_head.prev = new_head
    return new_head


def addToTail(tail: DoublyListNode, value: int) -> Optional[DoublyListNode]:
    tail.next = DoublyListNode(value)
    tail.next.prev = tail
    return tail.next


def addToMid(head: DoublyListNode, index: int, value: int):
    temp = head
    l = 0
    while temp is not None:
        l += 1
        temp = temp.next

    temp = head

    if index < 0 or index >= l:
        print("index is invalid")
        return

    for _ in range(index):
        temp = temp.next

    newNode = DoublyListNode(value)
    newNode.next = temp.next
    newNode.prev = temp

    temp.next.prev = newNode
    temp.next = newNode


def printLinkedList(head: DoublyListNode):
    cur = head
    while cur is not None:
        print(cur.value, end=" -> ")
        cur = cur.next


def printReverseLinkedList(tail: DoublyListNode):
    cur = tail
    while cur is not None:
        print(cur.value, end=" -> ")
        cur = cur.prev


def printArray(arr: [int]):
    for i in arr:
        print(i, end=", ")


if __name__ == "__main__":
    arr = [0] * 10

    for i in range(10):
        arr[i] = i

    printArray(arr)
    print()

    head = createDoublyLinkedList(arr)
    printLinkedList(head)

    print()

    tail = findTail(head)
    printReverseLinkedList(tail)

    print()

    head = addToHead(head, -1)
    printLinkedList(head)

    print()

    tail = addToTail(tail, 10)
    printReverseLinkedList(tail)

    print()

    addToMid(head, 0, 99)
    printLinkedList(head)
