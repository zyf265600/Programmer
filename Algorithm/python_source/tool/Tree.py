# coding=utf-8
from python_source.tool.Node import Node


class Tree(object):
    """树类"""

    def __init__(self, root=None):
        self.root = root

    def add(self, elem):
        """为树添加节点"""
        node = Node(elem)
        # 如果树是空的，则对根节点赋值
        if self.root == None:
            self.root = node
        else:
            queue = []
            queue.append(self.root)
            # 对已有的节点进行层次遍历
            while queue:
                # 弹出队列的第一个元素
                cur = queue.pop(0)
                if cur.left == None:
                    cur.left = node
                    return
                elif cur.right == None:
                    cur.right = node
                    return
                else:
                    # 如果左右子树都不为空，加入队列继续判断
                    queue.append(cur.left)
                    queue.append(cur.right)

    def init_tree(self):
        node_9 = Node(9)
        node_15 = Node(15)
        node_7 = Node(7)
        node_20 = Node(20, node_15, node_7)
        root = Node(3, node_9, node_20)
        return root

    # 与init_tree一致
    def init_tree2(self):
        node_9 = Node(9)
        node_15 = Node(15)
        node_7 = Node(7)
        node_20 = Node(20, node_15, node_7)
        root = Node(3, node_9, node_20)
        return root

    # 用于测试两个树合并
    def init_tree_for_merge1(self):
        node_5 = Node(5)
        node_3 = Node(3, node_5)
        node_2 = Node(2)
        root = Node(1, node_3, node_2)
        return root

    def init_tree_for_merge2(self):
        node_4 = Node(4)
        node_1 = Node(1, None, node_4)
        node_7 = Node(7)
        node_3 = Node(1, None, node_7)
        root = Node(2, node_1, node_3)
        return root

    # 用于测试树是否对称
    def init_tree_for_symmetric(self):
        node_5 = Node(5)
        node_6 = Node(6)
        node_3 = Node(3, node_5, node_6)
        node_4 = Node(4)
        node_2 = Node(2, node_3, node_4)

        node_55 = Node(5)
        node_66 = Node(6)
        node_33 = Node(3, node_66, node_55)
        node_44 = Node(4)
        node_22 = Node(2, node_44, node_33)

        root = Node(1, node_2, node_22)
        return root

    # 用于测试所有路径
    def init_tree_for_path(self):
        node_5 = Node(5)
        node_2 = Node(2, None, node_5)
        node_3 = Node(3)
        root = Node(1, node_2, node_3)
        return root

    # 用于测试路径总和
    def init_tree_for_path_sum(self):
        node_7 = Node(7)
        node_2 = Node(2)
        node_11 = Node(11, node_7, node_2)
        node_4 = Node(4, node_11, None)
        node_13 = Node(13)
        node_1 = Node(1)
        node_44 = Node(4, None, node_1)
        node_8 = Node(8, node_13, node_44)
        root = Node(5, node_4, node_8)
        return root

    # 用于测试翻转二叉树
    def init_tree_for_invert(self):
        node_1 = Node(1)
        node_3 = Node(3)
        node_2 = Node(2, node_1, node_3)
        node_6 = Node(6)
        node_9 = Node(9)
        node_7 = Node(7, node_6, node_9)
        root = Node(4, node_2, node_7)
        return root

    # 用于测试翻转二叉树
    def init_tree_for_bst_search(self):
        node_1 = Node(1)
        node_3 = Node(3)
        node_2 = Node(2, node_1, node_3)
        node_7 = Node(7)
        root = Node(4, node_2, node_7)
        return root

    def init_tree_for_valid_bst(self):
        node_6 = Node(6)
        node_3 = Node(3)
        node_4 = Node(4, node_3, node_6)
        node_1 = Node(1)
        root = Node(5, node_1, node_4)
        return root


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    print root
