package com.yugutou.charpter19_dp.level2;

/**
 * LeetCode279.给你一个整数n ，返回和为n的完全平方数的最少数量。
 */
public class NumSquares {
    public static void main(String[] args) {
        System.out.println(numSquares(12));
    }

    public static int numSquares(int n) {
        int[] f = new int[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = Integer.MAX_VALUE;
            for (int j = 1; j * j <= i; j++) {
                if (f[i - j * j] + 1 < f[i]) {
                    f[i] = f[i - j * j] + 1;
                }
            }
        }
        return f[n];
    }
}
