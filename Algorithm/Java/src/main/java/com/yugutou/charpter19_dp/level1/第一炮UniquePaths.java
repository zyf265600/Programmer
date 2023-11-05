package com.yugutou.charpter19_dp.level1;

/**
 * 路径问题
 * 第一炮：基本问题：统计路径总数
 * 递归实现
 */
public class 第一炮UniquePaths {
    public static void main(String[] args) {
        int m = 5, n = 3;
        System.out.println(uniquePaths(m, n));
    }

    public static int uniquePaths(int m, int n) {
        return search(m, n);
    }

    public static int search(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        return search(m - 1, n) + search(m, n - 1);
    }
}
