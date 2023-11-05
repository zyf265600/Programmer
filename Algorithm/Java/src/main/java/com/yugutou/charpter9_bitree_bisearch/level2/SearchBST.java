package com.yugutou.charpter9_bitree_bisearch.level2;


import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

/**
 * LeetCode 700.给定二叉搜索树（BST）的根节点和一个值。
 * 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。
 */
public class SearchBST {
    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBSTTree();
        System.out.println(searchBST(bTree.root, 2).val);
        System.out.println(searchBST2(bTree.root, 2).val);
    }

    /**
     * 递归方式实现
     *
     * @param root
     * @param val
     * @return
     */
    public static TreeNode searchBST(TreeNode root, int val) {
        if (root == null || val == root.val) return root;
        return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
    }

    /**
     * 迭代实现
     *
     * @param root
     * @param val
     * @return
     */
    public static TreeNode searchBST2(TreeNode root, int val) {
        while (root != null && val != root.val)
            root = val < root.val ? root.left : root.right;
        return root;
    }
}
