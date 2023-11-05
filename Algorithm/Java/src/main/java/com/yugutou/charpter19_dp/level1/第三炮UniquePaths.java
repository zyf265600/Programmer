package com.yugutou.charpter19_dp.level1;

import java.util.Arrays;

/**
 * 路径问题
 * 第三炮：基本问题：统计路径总数
 * 一维数组实现
 */
public class 第三炮UniquePaths {
    public static void main(String[] args) {
        int m = 3, n = 2;
        System.out.println(uniquePaths(m, n));
    }

    public static int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                //等式右边的 dp[j]是上一次计算后的，加上左边的dp[j-1]即为当前结果
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
}
