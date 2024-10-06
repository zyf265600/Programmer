package com.yugutou.charpter19_dp.level1;


/**
 * 路径问题
 * 第四炮：LeetCode64.最小路径和
 */
public class MinPathSum {
    public static void main(String[] args) {
        int[][] array = new int[3][3];
        array[0] = new int[]{1, 3, 1};
        array[1] = new int[]{1, 5, 1};
        array[2] = new int[]{4, 2, 1};
        System.out.println(minPathSum(array));
    }

    /**
     * 基于二维数组减少重复计算
     *
     * @param grid
     * @return
     */
    public static int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    f[i][j] = grid[i][j];
                } else {
                    int top = i - 1 >= 0 ? f[i - 1][j] + grid[i][j] : Integer.MAX_VALUE;
                    int left = j - 1 >= 0 ? f[i][j - 1] + grid[i][j] : Integer.MAX_VALUE;
                    f[i][j] = Math.min(top, left);
                }
            }
        }
        return f[m - 1][n - 1];
    }
}
