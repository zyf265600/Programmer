# coding=utf-8
import collections
from python_source.tool.Tree import Tree


#  最小深度
class MinDepth:
    def minDepth(self, root):
        if not root:
            return 0
        que = collections.deque([(root, 1)])
        while que:
            node, depth = que.popleft()
            if not node.left and not node.right:
                return depth
            if node.left:
                que.append((node.left, depth + 1))
            if node.right:
                que.append((node.right, depth + 1))
        return 0


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    minDepth = MinDepth()
    res = minDepth.minDepth(root)
    print res
