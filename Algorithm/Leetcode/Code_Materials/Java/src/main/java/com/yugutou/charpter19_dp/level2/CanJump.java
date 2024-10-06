package com.yugutou.charpter19_dp.level2;

public class CanJump {

    public static void main(String[] args) {
        int[] nums = {2, 3, 1, 1, 4};
        System.out.println(canJump(nums));
    }

    public static boolean canJump(int[] A) {
        if (A == null || A.length == 0) {
            return false;
        }
        int n = A.length;
        boolean[] f = new boolean[n];
        f[0] = true;
        for (int j = 1; j < n; j++) {
            f[j] = false;
            for (int i = 0; i < j; i++) {
                if (f[i] && (i + A[i] >= j)) {
                    f[j] = true;
                }
            }
        }
        return f[n - 1];
    }
}
