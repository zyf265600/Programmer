# coding=utf-8
from python_source.tool.Tree import Tree


def binaryTreePaths(root):
    res = []
    get_paths(root, [], res)
    return res


def get_paths(root, path, res):
    if root:
        path.append(str(root.val))
        left = get_paths(root.left, path, res)
        right = get_paths(root.right, path, res)
        if not left and not right:  # 如果root是叶子结点
            res.append("->".join(path))  # 把当前路径加入到结果列表中
        path.pop()  # 返回上一层递归时，要让当前路径恢复原样
        return True


if __name__ == "__main__":
    tree = Tree()

    root = tree.init_tree_for_path()
    res = binaryTreePaths(root)
    print res
