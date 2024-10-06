package com.yugutou.tools;

import java.util.ArrayList;
import java.util.List;

public class NTree {

    public NTreeNode root;

    public NTree() {
        root = null;
    }

    /**
     * 方法1：比较粗糙的创建二叉树关系
     */
    public NTreeNode buildNTree() {

        //子数
        List<NTreeNode> sub = new ArrayList<NTreeNode>();
        sub.add(new NTreeNode(5));
        sub.add(new NTreeNode(6));


        List<NTreeNode> nodes = new ArrayList<NTreeNode>();
        nodes.add(new NTreeNode(3, sub));
        nodes.add(new NTreeNode(2));
        nodes.add(new NTreeNode(4));

        NTreeNode root = new NTreeNode(3, nodes);


        return root;

    }


    /**
     * 前序遍历
     *
     * @param node
     */
    public void preOrder(NTreeNode node) {
        if (node != null) {
            System.out.print(node.val + "\t");
            for (NTreeNode item : node.children)
                preOrder(item);

        }
    }

    /**
     * 中序遍历 无意义了
     *
     * @param node
     */
    public void inOrder(NTreeNode node) {
//        if (node != null) {
//            inOrder(node.left);
//            System.out.print(node.val + "\t");
//            inOrder(node.right);
//        }
    }

    /**
     * 后序遍历
     *
     * @param node
     */
    public void postOrder(NTreeNode node) {
        if (node != null) {
            for (NTreeNode item : node.children) {
                postOrder(item);
            }
            System.out.print(node.val + "\t");
        }
    }

    public static void main(String[] args) {

        NTree bTree = new NTree();
        bTree.root = bTree.buildNTree();
        bTree.preOrder(bTree.root);
        System.out.println();
        bTree.inOrder(bTree.root);
        System.out.println();
        bTree.postOrder(bTree.root);


    }


}