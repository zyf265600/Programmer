package com.yugutou.charpter19_dp.level2;

/**
 * 路径中存在障碍物
 */
public class UniquePathsWithObstacles {
    public static void main(String[] args) {
        int[][] array = new int[3][3];
        array[0] = new int[]{0, 0, 0};
        array[1] = new int[]{0, 1, 0};
        array[2] = new int[]{0, 0, 0};
        System.out.println(uniquePathsWithObstacles(array));
    }

    public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n = obstacleGrid.length, m = obstacleGrid[0].length;
        int[] dp = new int[m];
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[m - 1];
    }
}
