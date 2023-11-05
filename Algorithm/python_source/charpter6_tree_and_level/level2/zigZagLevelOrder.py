# coding=utf-8
import collections

from python_source.tool.Tree import Tree
from collections import deque


class ZigzagLevelOrder:
    def zigzag_level_order(self, root):
        if not root: return []
        dq, res, flag = deque(), [], 1
        dq.append(root)
        while len(dq) != 0:
            temp = []
            for i in range(len(dq)):
                node = dq.popleft()
                temp.append(node.val)
                if node.left: dq.append(node.left)
                if node.right: dq.append(node.right)
            if flag == 1:
                res.append(temp[:])
                flag = 0
            else:
                res.append(temp[::-1])
                flag = 1
        return res


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    zigzagLevelOrder = ZigzagLevelOrder()
    res = zigzagLevelOrder.zigzag_level_order(root)
    print res
