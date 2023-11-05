# coding=utf-8
import collections

from python_source.tool.Tree import Tree

class LevelOrderBottom:
    def level_order_bottom(self, root):
        levelOrder = list()
        if not root:
            return levelOrder

        q = collections.deque([root])
        while q:
            level = list()
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            levelOrder.append(level)
        return levelOrder[::-1]


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    levelOrderBottom = LevelOrderBottom()
    res = levelOrderBottom.level_order_bottom(root)
    print res
