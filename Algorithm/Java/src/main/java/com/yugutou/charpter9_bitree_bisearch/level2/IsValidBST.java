package com.yugutou.charpter9_bitree_bisearch.level2;


import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

import java.util.Deque;
import java.util.LinkedList;

/**
 * LeetCode98.给你一个二叉树的根节点 root ，
 * 判断其是否是一个有效的二叉搜索树。
 */
public class IsValidBST {

    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBSTTree();
        System.out.println(isValidBST2(bTree.root));
        System.out.println(isValidBST(bTree.root));
    }

    /**
     * 递归实现
     */

    static long pre = Long.MIN_VALUE;

    public static boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        // 如果左子树下某个元素不满足要求，则退出
        if (!isValidBST(root.left)) {
            return false;
        }
        // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
        if (root.val <= pre) {
            return false;
        }
        pre = root.val;
        // 访问右子树
        return isValidBST(root.right);
    }

    /**
     * 迭代实现
     *
     * @param root
     * @return
     */
    public static boolean isValidBST2(TreeNode root) {
        Deque<TreeNode> stack = new LinkedList<TreeNode>();
        double inorder = 0;
        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }
            root = stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root.val <= inorder) {
                return false;
            }
            inorder = root.val;
            root = root.right;
        }
        return true;
    }


}
