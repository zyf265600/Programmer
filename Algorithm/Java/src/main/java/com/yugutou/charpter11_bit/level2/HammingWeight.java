package com.yugutou.charpter11_bit.level2;

public class HammingWeight {
    public static void main(String[] args) {
        System.out.println(hammingWeight1(11));
        System.out.println(hammingWeight2(11));

    }

    /**
     * 方法1：n整体循环移位
     *
     * @param n
     * @return
     */
    public static int hammingWeight1(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            count += (n >> i) & 1;
        }
        return count;
    }

    /**
     * 方法2：根据1的数量循环
     *
     * @param n
     * @return
     */
    public static int hammingWeight2(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
}
