package com.yugutou.charpter9_bitree_bisearch.level2;


import com.yugutou.tools.TreeNode;

/**
 * LeetCode108
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，
 * 请你将其转换为一棵 高度平衡 二叉搜索树。
 */
public class SortedArrayToBST {
    public static void main(String[] args) {
        int[] nums = {-10, -3, 0, 5, 9};

        TreeNode node=sortedArrayToBST(nums);
        System.out.println(node.val);
    }

    public static TreeNode sortedArrayToBST(int[] nums) {
        return dfs(nums, 0, nums.length - 1);
    }

    private static TreeNode dfs(int[] nums, int lo, int hi) {
        if (lo > hi) {
            return null;
        }
        // 以升序数组的中间元素作为根节点 root。
        int mid = lo + (hi - lo) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        // 递归的构建 root 的左子树与右子树。
        root.left = dfs(nums, lo, mid - 1);
        root.right = dfs(nums, mid + 1, hi);
        return root;
    }
}
