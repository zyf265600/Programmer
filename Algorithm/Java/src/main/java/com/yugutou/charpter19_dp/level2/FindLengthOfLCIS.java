package com.yugutou.charpter19_dp.level2;

/**
 * LeetCode674.给定一个未经排序的整数数组，
 * 找到最长且连续递增的子序列，并返回该序列的长度。
 */
public class FindLengthOfLCIS {
    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 4, 7};
        System.out.println(findLengthOfLCIS(nums));
    }

    public static int findLengthOfLCIS(int[] nums) {
        int[] dp = new int[nums.length];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = 1;
        }
        int res = 1;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                dp[i + 1] = dp[i] + 1;
            }
            res = res > dp[i + 1] ? res : dp[i + 1];
        }
        return res;

    }
}
