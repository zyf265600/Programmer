package com.yugutou.charpter11_bit.level2;

import java.util.Arrays;

public class CountBits {
    public static void main(String[] args) {
        System.out.println(Arrays.toString(countBits(2)));
        System.out.println(Arrays.toString(countBits2(2)));
    }

    /**
     * 方法1：统一移位统计
     *
     * @param num
     * @return
     */
    public static int[] countBits(int num) {
        int[] bits = new int[num + 1];
        for (int i = 0; i <= num; i++) {
            for (int j = 0; j < 32; j++) {
                bits[i] += (i >> j) & 1;
            }
        }
        return bits;
    }

    /**
     * 方法2：通过技巧x &= (x - 1);计算
     *
     * @param num
     * @return
     */
    public static int[] countBits2(int num) {
        int[] bits = new int[num + 1];
        for (int i = 0; i <= num; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }

    public static int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

}
