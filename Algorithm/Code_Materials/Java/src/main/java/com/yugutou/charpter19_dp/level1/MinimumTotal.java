package com.yugutou.charpter19_dp.level1;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 路径问题
 * 第四炮：LeetCode120.三角形最小路径和
 */
public class MinimumTotal {
    public static void main(String[] args) {

        List<List<Integer>> list = new ArrayList<>();
        list.add(Arrays.asList(2, 0, 0, 0));
        list.add(Arrays.asList(3, 4, 0, 0));
        list.add(Arrays.asList(6, 5, 7, 0));
        list.add(Arrays.asList(4, 1, 8, 3));

        System.out.println(minimumTotal(list));
    }


    /**
     * @param tri
     * @return
     */
    public static int minimumTotal(List<List<Integer>> tri) {
        int n = tri.size();
        int ans = Integer.MAX_VALUE;
        int[][] f = new int[n][n];
        f[0][0] = tri.get(0).get(0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                int val = tri.get(i).get(j);
                f[i][j] = Integer.MAX_VALUE;
                if (j != 0) f[i][j] = Math.min(f[i][j], f[i - 1][j - 1] + val);
                if (j != i) f[i][j] = Math.min(f[i][j], f[i - 1][j] + val);
            }
        }
        for (int i = 0; i < n; i++) ans = Math.min(ans, f[n - 1][i]);
        return ans;
    }


}
