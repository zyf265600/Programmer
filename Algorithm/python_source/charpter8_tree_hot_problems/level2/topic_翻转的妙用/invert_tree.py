# coding=utf-8
from python.unit6_tree.part1_basic.Tree import Tree


#  判断树是否一样
class InvertTree:
    # 基于前序遍历方式
    def invertTree1(self, root):
        # 递归函数的终止条件，节点为空时返回
        if not root:
            return None
        # 将当前节点的左右子树交换
        root.left, root.right = root.right, root.left
        # 递归交换当前节点的 左子树和右子树
        self.invertTree1(root.left)
        self.invertTree1(root.right)
        # 函数返回时就表示当前这个节点，以及它的左右子树
        # 都已经交换完了
        return root

    def invertTree2(self, root):
        if not root:
            return root
        left = self.invertTree2(root.left)
        right = self.invertTree2(root.right)
        root.left, root.right = right, left
        return root

    # 基于层次遍历方式
    def invertTree3(self, root):
        if not root:
            return None
        # 将二叉树中的节点逐层放入队列中，再迭代处理队列中的元素
        queue = [root]
        while queue:
            # 每次都从队列中拿一个节点，并交换这个节点的左右子树
            tmp = queue.pop(0)
            tmp.left, tmp.right = tmp.right, tmp.left
            # 如果当前节点的左子树不为空，则放入队列等待后续处理
            if tmp.left:
                queue.append(tmp.left)
            # 如果当前节点的右子树不为空，则放入队列等待后续处理
            if tmp.right:
                queue.append(tmp.right)
        # 返回处理完的根节点
        return root


if __name__ == "__main__":
    tree = Tree()

    root = tree.init_tree_for_invert()
    invertTree = InvertTree()
    res = invertTree.invertTree2(root)
    print res
