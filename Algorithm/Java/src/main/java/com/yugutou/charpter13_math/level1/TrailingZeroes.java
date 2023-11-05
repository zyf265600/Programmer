package com.yugutou.charpter13_math.level1;

public class TrailingZeroes {
    public static void main(String[] args) {
        System.out.println(trailingZeroes(25));
    }

    public static int trailingZeroes(int n) {
        int cnt = 0;
        for (long num = 5; n / num > 0; num *= 5) {
            cnt += n / num;
        }
        return cnt;
    }
}
