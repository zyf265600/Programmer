package com.yugutou.charpter19_dp.level2;

/**
 * LeetCode300.
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 */
public class LengthOfLIS {
    public static void main(String[] args) {
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println(lengthOfLIS(nums));
    }

    public static int lengthOfLIS(int[] A) {
        int n = A.length;
        if (n == 0) {
            return 0;
        }
        int[] f = new int[n];
        int i, j, res = 0;
        for (j = 0; j < n; j++) {
            f[j] = 1;
            for (i = 0; i < j; i++) {
                if (A[i] < A[j] && f[i] + 1 > f[j]) {
                    f[j] = f[i] + 1;
                }
            }
            res = Math.max(res, f[j]);
        }
        return res;
    }
}

