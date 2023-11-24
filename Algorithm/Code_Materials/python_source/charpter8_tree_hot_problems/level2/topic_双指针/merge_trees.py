# coding=utf-8
from python_source.tool.Node import Node
from python_source.tool.Tree import Tree

#  判断树是否一样
class MergeTrees:
    def mergeTrees(self, t1, t2):
        if not t1:
            return t2
        if not t2:
            return t1

        merged = Node(t1.val + t2.val)
        merged.left = self.mergeTrees(t1.left, t2.left)
        merged.right = self.mergeTrees(t1.right, t2.right)
        return merged


if __name__ == "__main__":
    tree = Tree()
    q = tree.init_tree_for_merge1()
    p = tree.init_tree_for_merge2()
    mergeTrees = MergeTrees()
    res = mergeTrees.mergeTrees(q, p)
    print res
