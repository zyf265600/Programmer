from typing import List


class ListNode:
    def __init__(self, x, next_node=None):
        self.val = x
        self.next = next_node

    @staticmethod
    def create_head(nums: List[int]):
        if len(nums) == 0 or nums is None:
            return None
        head = ListNode(nums[0])
        p = head
        for i in range(1, len(nums)):
            p.next = ListNode(nums[i])
            p = p.next
        return head

    @staticmethod
    def print(head: 'ListNode'):
        p = head
        while p:
            arrow = ' -> ' if p.next else ''
            print(p.val, end=arrow)
            p = p.next
        print()

from typing import List, Union


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    @staticmethod
    def create_root(nums: List[Union[int, None]]):
        if len(nums) == 0 or nums is None:
            return None
        root = TreeNode(nums[0])
        nodes = [root]
        i = 1
        while i < len(nums):
            node = nodes.pop(0)
            if nums[i] is not None:
                node.left = TreeNode(nums[i])
                nodes.append(node.left)
            i += 1
            if i < len(nums) and nums[i] is not None:
                node.right = TreeNode(nums[i])
                nodes.append(node.right)
            i += 1
        return root
