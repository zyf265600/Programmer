# coding=utf-8
from python_source.tool.Tree import Tree

# 最大深度
class MaxDepth:
    def maxDepth(self, root):
        if root is None:
            return 0
        else:
            left_height = self.maxDepth(root.left)
            right_height = self.maxDepth(root.right)
            return max(left_height, right_height) + 1

    # 层次遍历法
    def maxDepth2(self, root):
        maxDepth = 0
        if not root:
            return maxDepth
        myQueue = [root]
        while myQueue:
            maxDepth += 1
            for i in range(len(myQueue)):
                node = myQueue.pop(0)
                if node.left:
                    myQueue.append(node.left)
                if node.right:
                    myQueue.append(node.right)
        return maxDepth

if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    maxDepth = MaxDepth()
    res = maxDepth.maxDepth2(root)
    print res
