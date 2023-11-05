# coding=utf-8
from python_source.tool.Tree import Tree

#  判断树是否一样
class HasPathSum:
    def hasPathSum(self, root, sum):
        if not root:
            return False
        if not root.left and not root.right:
            return sum == root.val
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)


if __name__ == "__main__":
    tree = Tree()

    root = tree.init_tree_for_path_sum()
    hasPathSum = HasPathSum()
    res = hasPathSum.hasPathSum(root,22)
    print res
