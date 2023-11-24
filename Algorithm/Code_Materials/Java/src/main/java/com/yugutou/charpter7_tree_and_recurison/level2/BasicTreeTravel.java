package com.yugutou.charpter7_tree_and_recurison.level2;

import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * 基本的前中后序遍历
 */
public class BasicTreeTravel {
    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBinaryTree();
//        bTree.root = bTree.buildBinaryTree();
        int testMethod = 1;

        List<Integer> res = new ArrayList<Integer>();
        switch (testMethod) {
            case 1://前序
                preOrder(bTree.root, res);
                break;
            case 2:
                inOrder(bTree.root, res);
                break;
            case 3:
                postOrder(bTree.root, res);
                break;
        }
        System.out.println(res);
    }


    /**
     * 前序遍历，将结果返回到list中
     *
     * @param root
     * @param res
     */

    public static void preOrder(TreeNode root, List<Integer> res) {
        if (root == null) { return;}
        res.add(root.val);
        preOrder(root.left, res);
        preOrder(root.right, res);
    }

    /**
     * 中序遍历，将结果返回到list中
     *
     * @param root
     * @param res
     */

    public static void inOrder(TreeNode root, List<Integer> res) {
        if (root == null) { return;
        }
        inOrder(root.left, res);
        res.add(root.val);
        inOrder(root.right, res);
    }

    /**
     * 后序遍历，将结果返回到list中
     *
     * @param root
     * @param res
     */

    public static void postOrder(TreeNode root, List<Integer> res) {
        if (root == null) {
            return;
        }
        postOrder(root.left, res);
        postOrder(root.right, res);
        res.add(root.val);
    }

}
