# coding=utf-8
from python_source.tool.Tree import Tree


# 三种递归方式
class Visit:
    # 前序遍历
    def preOrder(self, root):
        if not root:
            return 0
        print root.val
        self.preOrder(root.left)
        self.preOrder(root.right)

    # 中序遍历
    def inOrder(self, root):
        if not root:
            return 0

        self.inOrder(root.left)
        print root.val
        self.inOrder(root.right)

    # 后序遍历
    def postOrder(self, root):
        if not root:
            return 0

        self.postOrder(root.left)
        self.postOrder(root.right)
        print root.val


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    visit = Visit()

    visit.postOrder(root)
