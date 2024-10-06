# coding=utf-8
from python_source.tool.Tree import Tree

# 平衡树判断
class IsBalanced:
    def isBalanced(self, root):
        def height(root):
            if not root:
                return 0
            leftHeight = height(root.left)
            rightHeight = height(root.right)
            if leftHeight == -1 or rightHeight == -1 or abs(leftHeight - rightHeight) > 1:
                return -1
            else:
                return max(leftHeight, rightHeight) + 1

        return height(root) >= 0


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    isBalanced = IsBalanced()
    res = isBalanced.isBalanced(root)
    print res
