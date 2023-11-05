# coding=utf-8
from python_source.list_node import ListNode, init_list


class IsPalindrome:
    def isPalindrome1(self, head):
        cur, length = head, 0
        result = []
        # 遍历链表，把所有节点上的元素都存储到列表 result 中
        while cur is not None:
            length += 1
            result.append(cur.val)
            cur = cur.next
            # 定义2个指针，一个从头开始往后，另一个从最后开始往前
        left, right = 0, length - 1
        while left < right:
            if result[left] != result[right]:
                return False
            left += 1
            right -= 1
        return True

    # 方法2：双指针+反转
    def isPalindrome2(self, head):
        fake = ListNode(-1)
        fake.next = head
        fast = slow = fake
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        post = slow.next
        slow.next = None
        pre = head

        rev = None
        # 反转
        while post:
            tmp = post.next
            post.next = rev
            rev = post
            post = tmp

        part1 = pre
        part2 = rev
        while part1 and part2:
            if part1.val != part2.val:
                return False
            part1 = part1.next
            part2 = part2.next
        return True


if __name__ == '__main__':
    # 先构造题目要求的链表,简单构造即可
    nums = [1, 2, 2, 1]
    list = init_list(nums)
    isPalindrome = IsPalindrome()
    print isPalindrome.isPalindrome1(list)
