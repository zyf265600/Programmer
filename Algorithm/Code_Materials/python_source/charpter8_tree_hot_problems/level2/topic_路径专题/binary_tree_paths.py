# coding=utf-8
from python_source.tool.Tree import Tree

#  判断树是否一样
class BinaryTreePaths:
    def binaryTreePaths(self, root):
        def construct_paths(root, path):
            if root:
                path += str(root.val)
                if not root.left and not root.right:  # 当前节点是叶子节点
                    paths.append(path)  # 把路径加入到答案中
                else:
                    path += '->'  # 当前节点不是叶子节点，继续递归遍历
                    construct_paths(root.left, path)
                    construct_paths(root.right, path)

        paths = []
        construct_paths(root, '')
        return paths


if __name__ == "__main__":
    tree = Tree()

    root = tree.init_tree_for_path()
    binaryTreePaths = BinaryTreePaths()
    res = binaryTreePaths.binaryTreePaths(root)
    print res
