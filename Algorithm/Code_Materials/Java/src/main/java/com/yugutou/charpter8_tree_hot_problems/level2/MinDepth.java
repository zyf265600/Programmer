package com.yugutou.charpter8_tree_hot_problems.level2;

import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

import java.util.LinkedList;

/**
 * leetcode104 最大深度和最小深度问题
 */
public class MinDepth {
    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBinaryTreeComplex();
        int testMethod = 2;
        int result = 0;
        switch (testMethod) {
            case 1://通过递归计算二叉树的深度
                result = minDepth_1(bTree.root);
                break;
            case 2://通过层次遍历计算二叉树的深度
                result = minDepth_2(bTree.root);
                break;
        }
        System.out.println(result);
    }

    /**
     * 通过递归计算二叉树的最小
     *
     * @param root
     * @return
     */
    public static int minDepth_1(TreeNode root) {
        if (root == null) {
            return 0;
        }

        if (root.left == null && root.right == null) {
            return 1;
        }

        int min_depth = Integer.MAX_VALUE;
        if (root.left != null) {
            min_depth = Math.min(minDepth_1(root.left), min_depth);
        }
        if (root.right != null) {
            min_depth = Math.min(minDepth_1(root.right), min_depth);
        }
        return min_depth + 1;
    }

    /**
     * 通过层次遍历来求最大深度
     *
     * @return
     */
    public static int minDepth_2(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int minDepth = 0;

        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while (queue.size() > 0) {
            //获取当前队列的长度，这个长度相当于 当前这一层的节点个数
            int size = queue.size();
            minDepth++;
            for (int i = 0; i < size; ++i) {
                TreeNode t = queue.remove();
                if (t.left == null && t.right == null) {
                    return minDepth;
                }
                if (t.left != null) {
                    queue.add(t.left);
                }
                if (t.right != null) {
                    queue.add(t.right);
                }
            }
        }
        return 0;
    }

}
