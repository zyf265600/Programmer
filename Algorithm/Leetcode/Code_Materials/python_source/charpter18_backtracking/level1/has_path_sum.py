# coding=utf-8
from python_source.tool.Tree import Tree

#  判断树是否一样
class HasPathSum:
    def pathSum(self, root, targetSum):
        ret = list()
        path = list()

        def dfs(root, targetSum):
            if not root:
                return
            path.append(root.val)
            targetSum -= root.val
            if not root.left and not root.right and targetSum == 0:
                ret.append(path[:])
            dfs(root.left, targetSum)
            dfs(root.right, targetSum)
            path.pop()

        dfs(root, targetSum)
        return ret


if __name__ == "__main__":
    tree = Tree()

    root = tree.init_tree_for_path_sum()
    hasPathSum = HasPathSum()
    res = hasPathSum.hasPathSum(root,22)
    print res
