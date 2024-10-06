# coding=utf-8
from python_source.tool.Tree import Tree

#  判断树是否一样
class IsSymmetric:
    def isSymmetric(self, root):
        if not root:
            return True
        def dfs(left, right):
            # 递归的终止条件是两个节点都为空
            # 或者两个节点中有一个为空
            # 或者两个节点的值不相等
            if not (left or right):
                return True
            if not (left and right):
                return False
            if left.val != right.val:
                return False
            return dfs(left.left, right.right) and dfs(left.right, right.left)

        # 用递归函数，比较左节点，右节点
        return dfs(root.left, root.right)


if __name__ == "__main__":
    tree = Tree()

    root = tree.init_tree_for_symmetric()
    isSymmetric = IsSymmetric()
    res = isSymmetric.isSymmetric(root)
    print res
