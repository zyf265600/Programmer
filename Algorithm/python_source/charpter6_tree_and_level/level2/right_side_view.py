# coding=utf-8
import collections
from python_source.tool.Tree import Tree
from collections import deque


class RightSideView:
    def right_side_view(self, root):
        rightmost_value_at_depth = dict()  # 深度为索引，存放节点的值
        max_depth = -1

        queue = deque([(root, 0)])
        while queue:
            node, depth = queue.popleft()

            if node is not None:
                # 维护二叉树的最大深度
                max_depth = max(max_depth, depth)

                # 由于每一层最后一个访问到的节点才是我们要的答案，因此不断更新对应深度的信息即可
                rightmost_value_at_depth[depth] = node.val

                queue.append((node.left, depth + 1))
                queue.append((node.right, depth + 1))

        return [rightmost_value_at_depth[depth] for depth in range(max_depth + 1)]


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    rightSideView = RightSideView()
    res = rightSideView.right_side_view(root)
    print res
