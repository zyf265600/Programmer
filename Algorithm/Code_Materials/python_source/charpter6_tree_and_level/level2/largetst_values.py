# coding=utf-8

import collections

from python_source.tool.Tree import Tree
from collections import deque


class LargestValues:
    def largest_values(self, root):
        if root is None:
            return []
        ans = []
        q = [root]
        while q:
            maxVal = -100000
            tmp = q
            q = []
            for node in tmp:
                maxVal = max(maxVal, node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(maxVal)
        return ans


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    largestValues = LargestValues()
    res = largestValues.largest_values(root)
    print res
