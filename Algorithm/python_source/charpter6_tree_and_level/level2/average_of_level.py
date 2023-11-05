# coding=utf-8
import collections


from collections import deque

from python_source.tool.Tree import Tree


class AverageOfLevels:
    def average_of_levels(self, root):
        averages = list()
        queue = collections.deque([root])
        while queue:
            total = 0
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                total += node.val
                left, right = node.left, node.right
                if left:
                    queue.append(left)
                if right:
                    queue.append(right)
            averages.append(total / size)
        return averages


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    averageOfLevels = AverageOfLevels()
    res = averageOfLevels.average_of_levels(root)
    print res
