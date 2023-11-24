# coding=utf-8
from collections import deque

from python.unit6_tree.part1_basic.Tree import Tree


#  最底层最左侧的值
class FindBottomLeftValue:
    def findBottomLeftValue(self, root):
        q = deque([root])
        while q:
            node = q.popleft()
            if node.right:
                q.append(node.right)
            if node.left:
                q.append(node.left)
            ans = node.val
        return ans


if __name__ == "__main__":
    tree = Tree()

    root = tree.init_tree_for_invert()
    findBottomLeftValue = FindBottomLeftValue()
    res = findBottomLeftValue.findBottomLeftValue(root)
    print res
