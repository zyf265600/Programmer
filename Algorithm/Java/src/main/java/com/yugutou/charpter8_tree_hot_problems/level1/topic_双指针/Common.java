package com.yugutou.charpter8_tree_hot_problems.level1.topic_双指针;

import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

/**
 * LeetCode100 判断两棵树是否相同
 */
public class Common {
    public static void main(String[] args) {
        BinaryTree bTree1 = new BinaryTree();
        bTree1.root = bTree1.buildBinaryTree();

        BinaryTree bTree2 = new BinaryTree();
        bTree1.root = bTree2.buildBinaryTree();

        boolean result = isSameTree(bTree1.root, bTree2.root);

        System.out.println(result);
    }

    public static boolean isSameTree(TreeNode p, TreeNode q) {
        //如果都为空我们就认为他是相同的
        if (p == null && q == null)
            return true;
        //如果一个为空，一个不为空，很明显不可能是相同的树，直接返回false即可
        if (p == null || q == null)
            return false;
        //如果这两个节点都不为空并且又不相等，所以他也不可能是相同的树，直接返回false
        if (p.val != q.val)
            return false;
        //走到这一步说明节点p和q是完全相同的，我们只需要在比较他们的左右子节点即可
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
