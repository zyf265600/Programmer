package com.yugutou.charpter13_math.level2;

import java.util.Arrays;

/**
 * 数组实现整数加法
 */
public class PlusOne {
    public static void main(String[] args) {
        int[] digital = {9};
        System.out.println(Arrays.toString(plusOne(digital)));
    }

    public static int[] plusOne(int[] digits) {
        int len = digits.length;
        for (int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0)
                return digits;
        }
        // 比较巧妙的设计
        digits = new int[len + 1];
        digits[0] = 1;
        return digits;
    }


}
