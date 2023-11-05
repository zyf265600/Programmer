# coding=utf-8
from python_source.tool.Tree import Tree


class Traversal:
    # 前序-迭代
    def preorderTraversal(self, root):
        res = list()
        if not root:
            return res

        stack = []
        node = root
        while stack or node:
            while node:
                res.append(node.val)
                stack.append(node)
                node = node.left
            node = stack.pop()
            node = node.right
        return res

    # 中序-迭代
    def inorderTraversal(self,root):
        if not root:
            return []

        res = []
        stack = []

        while stack or root:
            while root:
                stack.append(root)
                root = root.left

            node = stack.pop()
            res.append(node.val)
            root = node.right

        return res

    # 后序-迭代
    def postorderTraversal(self, root):
        res = []
        if root is None:
            return res

        stack = []
        node = root

        while stack or node:
            while node:
                res.append(node.val)
                stack.append(node)
                node = node.right

            node = stack.pop()
            node = node.left

        res.reverse()

        return res


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    visit = Traversal()

    print visit.preorderTraversal(root)
    print visit.inorderTraversal(root)
    print visit.postorderTraversal(root)
