package com.yugutou.charpter18_backtracking.level1;



import com.yugutou.tools.BinaryTree;
import com.yugutou.tools.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * LeetCode257 二叉树的所有路径
 */
public class BinaryTreePaths {
    static List<String> ans = new ArrayList<>();

    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();
        bTree.root = bTree.buildBinaryTree();
        List<String> result = binaryTreePaths(bTree.root);
        System.out.println(result);
    }

    public static List<String> binaryTreePaths(TreeNode root) {

        dfs(root, new ArrayList<>());
        return ans;
    }

    private static void dfs(TreeNode root, List<Integer> temp) {
        //空节点返回
        if (root == null) return;
        temp.add(root.val);
        //如果是叶子节点记录结果
        if (root.left == null && root.right == null) {
            ans.add(getPathString(temp));
        }
        dfs(root.left, temp);
        dfs(root.right, temp);
        temp.remove(temp.size() - 1);
    }

    //拼接结果
    private static String getPathString(List<Integer> temp) {
        StringBuilder sb = new StringBuilder();
        sb.append(temp.get(0));
        for (int i = 1; i < temp.size(); ++i) {
            sb.append("->").append(temp.get(i));
        }
        return sb.toString();
    }
}
