package com.yugutou.charpter8_tree_hot_problems.level1.topic3_翻转;

import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

import java.util.LinkedList;

/**
 * leetcode104 翻转问题
 */
public class Invert {
    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();
//        bTree.root = bTree.buildBinaryTree();
        bTree.root = bTree.buildBinaryTree();

        TreeNode result = null;
        //LeetCode101 对称二叉树
        int testMethod = 1;
        switch (testMethod) {
            case 1:
                result = invertTree_1(bTree.root);
                break;
            case 2:
                result = invertTree_2(bTree.root);
                break;
            case 3:
                result = invertTree_3(bTree.root);
                break;
        }

        System.out.println(result.val);
    }

    /**
     * 方法1：递归-前序
     *
     * @param root
     * @return
     */
    public static TreeNode invertTree_1(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        TreeNode left = invertTree_1(root.left);
        TreeNode right = invertTree_1(root.right);
        return root;

    }

    /**
     * 方法2：递归-后序
     *
     * @param root
     * @return
     */
    public static TreeNode invertTree_2(TreeNode root) {
        if (root == null) {
            return null;
        }
        TreeNode left = invertTree_2(root.left);
        TreeNode right = invertTree_2(root.right);
        root.left = right;
        root.right = left;
        return root;
    }

    /**
     * 方法3：迭代
     *
     * @param root
     * @return
     */
    public static TreeNode invertTree_3(TreeNode root) {
        if (root == null) {
            return null;
        }
        //将二叉树中的节点逐层放入队列中，再迭代处理队列中的元素
        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            //每次都从队列中拿一个节点，并交换这个节点的左右子树
            TreeNode tmp = queue.poll();
            TreeNode left = tmp.left;
            tmp.left = tmp.right;
            tmp.right = left;
            //如果当前节点的左子树不为空，则放入队列等待后续处理
            if (tmp.left != null) {
                queue.add(tmp.left);
            }
            //如果当前节点的右子树不为空，则放入队列等待后续处理
            if (tmp.right != null) {
                queue.add(tmp.right);
            }
        }

        return root;
    }

}
