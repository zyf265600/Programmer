package com.yugutou.charpter19_dp.level2;

public class NumDecodings {
    public static void main(String[] args) {
        String ss = "12";
        System.out.println(numDecodings(ss));
    }

    public static int numDecodings(String s) {
        int n = s.length();
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) != '0') {
                f[i] += f[i - 1];
            }
            if (i > 1 && (check(s, i))) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }

    public static boolean check(String s, int i) {
        if (s.charAt(i - 2) == '0') {
            return false;
        }
        if ((s.charAt(i - 2) - '0') * 10 + (s.charAt(i - 1) - '0') > 26) {
            return false;
        }
        return true;
    }

}
