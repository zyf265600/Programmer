# coding=utf-8
import collections

from python_source.tool.Tree import Tree

#  判断树是否一样
class IsSameTree:
    def isSameTree(self, p, q):
        if not p and not q:
            return True
        elif not p or not q:
            return False
        elif p.val != q.val:
            return False
        else:
            return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


if __name__ == "__main__":
    tree = Tree()
    q = tree.init_tree()
    p = tree.init_tree2()
    isSameTree = IsSameTree()
    res = isSameTree.isSameTree(q, p)
    print res
