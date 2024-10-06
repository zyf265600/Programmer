package com.yugutou.charpter19_dp.level2;

/**
 * LeetCode198.打家劫舍。
 */
public class HouseRobber {
    public static void main(String[] args) {
        int[] A = {1, 2, 3, 1};
        System.out.println(houseRobber(A));
    }

    public static long houseRobber(int[] A) {
        int n = A.length;
        if (n == 0) return 0;
        long[] dp = new long[n + 1];
        dp[0] = 0;
        dp[1] = A[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + A[i - 1]);
        }
        return dp[n];
    }
}
