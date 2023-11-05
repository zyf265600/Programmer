# coding=utf-8

from python.unit3_linklist.part2_hot_problem.list_node import init_list, ListNode, print_linked_list


class AddTwoNumbers:
    # 方法1 使用栈实现
    def addTwoNumbers(self, l1, l2):
        st1 = []
        st2 = []
        while l1:
            st1.append(l1.val)
            l1 = l1.next
        while l2:
            st2.append(l2.val)
            l2 = l2.next
        carry = 0
        dummy = ListNode(0)
        while st1 or st2 or carry:
            adder1 = st1.pop() if st1 else 0
            adder2 = st2.pop() if st2 else 0
            sum = adder1 + adder2 + carry
            carry = 1 if sum >= 10 else 0
            sum = sum - 10 if sum >= 10 else sum
            cur = ListNode(sum)
            cur.next = dummy.next
            dummy.next = cur
        return dummy.next

    # 方法2 使用链表反转实现
    def reverseList(self, head):
        prev = None
        curr = head
        while curr:
            nextTemp = curr.next
            curr.next = prev
            prev = curr
            curr = nextTemp
        return prev

    def addTwoNumbersI(self, l1, l2):
        ans = ListNode(0, None)
        DUMMY_HEAD, res = ans, 0
        p1, p2 = l1, l2

        while p1 != None or p2 != None or res == 1:

            ans.next = ListNode(0, None)
            ans = ans.next

            if p1 != None and p2 != None:
                sums = p1.val + p2.val
                if sums + res < 10:
                    ans.val = sums + res
                    res = 0
                else:
                    ans.val = sums + res - 10
                    res = 1
                p1, p2 = p1.next, p2.next

            elif p1 == None and p2 != None:
                sums = p2.val
                if sums + res < 10:
                    ans.val = sums + res
                    res = 0
                else:
                    ans.val = sums + res - 10
                    res = 1
                p2 = p2.next

            elif p2 == None and p1 != None:
                sums = p1.val
                if sums + res < 10:
                    ans.val = sums + res
                    res = 0
                else:
                    ans.val = sums + res - 10
                    res = 1
                p1 = p1.next

            else:
                ans.val = res
                res = 0
        return DUMMY_HEAD.next

    # 调用入口
    def addTwoNumbers2(self, l1, l2):
        return self.reverseList(self.addTwoNumbersI(self.reverseList(l1), self.reverseList(l2)))


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums1 = [6, 1, 7]
    list1 = init_list(nums1)

    nums2 = [2, 9, 5]
    list2 = init_list(nums2)

    addTwoNumbers = AddTwoNumbers()
    list3 = addTwoNumbers.addTwoNumbers2(list1, list2)
    print_linked_list(list3)
