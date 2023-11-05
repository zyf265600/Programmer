package com.yugutou.tools;

public class BinaryTree {

    public TreeNode root;

    public BinaryTree() {
        root = null;
    }

    /**
     * 方法1：比较粗糙的创建二叉树关系
     */
    public TreeNode buildBinaryTree() {
        TreeNode node = new TreeNode(3);
        node.left = new TreeNode(9);
        node.right = new TreeNode(20);
        node.right.right = new TreeNode(7);
        node.right.left = new TreeNode(15);
        return node;
    }

    /**
     * 用于搜索树的公共父结点问题
     * @return
     */

    public static TreeNode buildLowestCommonAncestor() {
        TreeNode node = new TreeNode(6);
        node.left = new TreeNode(2);
        node.right = new TreeNode(8);

        node.left.left = new TreeNode(0);
        node.left.right = new TreeNode(4);

        node.left.right.left = new TreeNode(3);
        node.left.right.right = new TreeNode(5);

        node.right.left = new TreeNode(7);
        node.right.right = new TreeNode(9);

        return node;

    }

    /**
     * 对称的二叉树
     *
     * @return
     */
    public TreeNode buildBinaryTree3() {
        TreeNode node = new TreeNode(3);
        node.left = new TreeNode(9);
        node.right = new TreeNode(9);
        node.right.right = new TreeNode(7);
        node.right.left = new TreeNode(15);

        node.left.right = new TreeNode(15);
        node.left.left = new TreeNode(7);

        return node;

    }

    /**
     * 建立搜索树
     */
    public TreeNode buildBSTTree() {
        TreeNode node = new TreeNode(4);
        node.left = new TreeNode(2);
        node.right = new TreeNode(7);
        node.left.left = new TreeNode(1);
        node.left.right = new TreeNode(3);
        return node;
    }

    /**
     * 构造一个相对复杂的二叉树
     *
     * @return
     */
    public TreeNode buildBinaryTreeComplex() {
        TreeNode node = new TreeNode(1);
        node.left = new TreeNode(2);
        node.left.left = new TreeNode(3);
        node.left.left.right = new TreeNode(4);
        node.left.left.right.right = new TreeNode(5);
        node.left.left.right.right.left = new TreeNode(6);
        node.left.left.right.right.left.left = new TreeNode(8);
        node.left.left.right.right.left.right = new TreeNode(8);

        node.right = new TreeNode(9);
        node.right.left = new TreeNode(10);
        node.right.right = new TreeNode(11);
        node.right.right.right = new TreeNode(12);
        node.right.right.right.left = new TreeNode(13);
        node.right.right.right.left.left = new TreeNode(15);
        node.right.right.right.left.right = new TreeNode(14);
        return node;

    }

    /**
     * 方法二： 根据大小来建立建二叉树
     *
     * @param node
     * @param data
     */
    public void buildTree(TreeNode node, int data) {
        if (root == null) {
            root = new TreeNode(data);
        } else {
            if (data < node.val) {
                if (node.left == null) {
                    node.left = new TreeNode(data);
                } else {
                    buildTree(node.left, data);
                }
            } else {
                if (node.right == null) {
                    node.right = new TreeNode(data);
                } else {
                    buildTree(node.right, data);
                }
            }
        }
    }


    /**
     * 前序遍历
     *
     * @param node
     */
    public void preOrder(TreeNode node) {
        if (node != null) {
            System.out.print(node.val + "\t");
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    /**
     * 中序遍历
     *
     * @param node
     */
    public void inOrder(TreeNode node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.val + "\t");
            inOrder(node.right);
        }
    }

    /**
     * 后序遍历
     *
     * @param node
     */
    public void postOrder(TreeNode node) {
        if (node != null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.print(node.val + "\t");
        }
    }

    public static void main(String[] args) {

        BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBinaryTree();
        bTree.preOrder(bTree.root);
        System.out.println();
        bTree.inOrder(bTree.root);
        System.out.println();
        bTree.postOrder(bTree.root);


    }


}