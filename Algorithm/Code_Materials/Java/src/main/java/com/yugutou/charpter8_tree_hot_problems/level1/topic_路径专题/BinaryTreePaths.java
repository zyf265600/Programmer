package com.yugutou.charpter8_tree_hot_problems.level1.topic_路径专题;

import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * LeetCode257 二叉树的所有路径
 */
public class BinaryTreePaths {
    public static void main(String[] args) {
         BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBinaryTree();
        List<String> result = binaryTreePaths(bTree.root);
        System.out.println(result);
    }

    public static List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        dfs(root, "", res);
        return res;
    }

    private static void dfs(TreeNode root, String path, List<String> res) {
        //如果为空，直接返回
        if (root == null)
            return;
        //如果是叶子节点，说明找到了一条路径，把它加入到res中
        if (root.left == null && root.right == null) {
            res.add(path + root.val);
            return;
        }
        //如果不是叶子节点，在分别遍历他的左右子节点
        dfs(root.left, path + root.val + "->", res);
        dfs(root.right, path + root.val + "->", res);
    }
}
