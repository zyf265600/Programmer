# coding=utf-8
from python_source.tool.Tree import Tree

class LevelOrder(object):
    # 将所有层输出到一行
    def basic_level_order(self, root):
        if not root:
            return []
        res = []
        queue = [root]
        while queue:
            # 获取当前队列的长度，这个长度相当于 当前这一层的节点个数
            size = len(queue)
            tmp = []
            # 将队列中的元素都拿出来(也就是获取这一层的节点)，放到临时list中
            # 如果节点的左/右子树不为空，也放入队列中
            # for _ in xrange(size):
            r = queue.pop(0)
            res.append(r.val)
            if r.left:
                queue.append(r.left)
            if r.right:
                queue.append(r.right)
            # 将临时list加入最终返回结果中
        return res

    # 不同的层分开打印
    def level_order(self, root):
        if not root:
            return []
        res = []
        queue = [root]
        while queue:
            # 获取当前队列的长度，这个长度相当于 当前这一层的节点个数
            size = len(queue)
            tmp = []
            # 将队列中的元素都拿出来(也就是获取这一层的节点)，放到临时list中
            # 如果节点的左/右子树不为空，也放入队列中
            for _ in xrange(size):
                r = queue.pop(0)
                tmp.append(r.val)
                if r.left:
                    queue.append(r.left)
                if r.right:
                    queue.append(r.right)
            # 将临时list加入最终返回结果中
            res.append(tmp)
        return res


if __name__ == "__main__":
    tree = Tree()
    root = tree.init_tree()
    levelOrder = LevelOrder()
    res = levelOrder.basic_level_order(root)
    print res
