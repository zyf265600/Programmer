from collections import deque


class TreeNode:
    def __init__(self, value: int):
        self.val = value
        self.left = None
        self.right = None


def traverse(root: TreeNode):
    if root is None:
        return
    print(root.val)  # pre-order
    traverse(root.left)
    # print(root.val) # in-order
    traverse(root.right)
    # print(root.val) # post-order


def levelOrderTravers(root: TreeNode):
    if root is None:
        return
    queue = deque()
    queue.append(root)

    while queue:
        cur : TreeNode = queue.popleft()
        print(cur.val)

        if cur.left is not None:
            queue.append(cur.left)
        if cur.right is not None:
            queue.append(cur.right)



if __name__ == "__main__":
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node4 = TreeNode(4)
    node5 = TreeNode(5)
    node6 = TreeNode(6)
    node7 = TreeNode(7)

    node1.left = node2

    node2.left = node3
    node2.right = node4

    node1.right = node5
    node5.left = node6
    node6.left = node7

    traverse(node1)
    print()
    levelOrderTravers(node1)

