package com.yugutou.charpter19_dp.level2;

import java.util.Arrays;

/**
 * LeetCode322.给你一个整数数组 coins ，表示不同面额的硬币，以及一个整数 amount ，表示总金额。
 * 计算并返回可以凑成总金额所需的最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 你可以认为每种硬币的数量是无限的。
 */
public class CoinChange {
    public static void main(String[] args) {
        int[] A = {2, 5, 7};
        System.out.println(coinChange(A, 27));
    }

    public static int coinChange(int[] coins, int M) {
        int max = M + 1;
        int[] dp = new int[M + 1];
        Arrays.fill(dp, max);
        dp[0] = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (coins[j] <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[M] > M ? -1 : dp[M];
    }
}
