package com.yugutou.charpter13_math.level3;

public class NthUglyNumber {
    public static void main(String[] args) {

        System.out.println(getUglyNumber(10));
        System.out.println(getUglyNumber2(10));
    }

    /**
     * 第一种方法，直接计算比较
     *
     * @param index
     * @return
     */
    public static int getUglyNumber(int index) {
        if (index <= 0) {
            return 0;
        }
        int number = 0;
        int uglyFound = 0;
        while (uglyFound < index) {
            ++number;
            if (nthUglyNumber1(number)) {
                ++uglyFound;
            }
        }
        return number;
    }

    public static boolean nthUglyNumber1(int index) {
        while (index % 2 == 0) {
            index /= 2;
        }
        while (index % 3 == 0) {
            index /= 3;
        }
        while (index % 5 == 0) {
            index /= 5;
        }
        return index == 1 ? true : false;
    }

    /**
     * 第二种方式，通过埃氏筛
     *
     * @param index
     * @return
     */

    public static int getUglyNumber2(int index) {
        if (index < 1)
            return 0;
        int[] pUglyNumbers = new int[index]; //依次保存第n个丑数
        pUglyNumbers[0] = 1; //第一个丑数是1
        int pMultiply2 = 0, pMultiply3 = 0, pMultiply5 = 0;

        for (int i = 1; i < index; i++) {
            int min = getMin(pUglyNumbers[pMultiply2] * 2, pUglyNumbers[pMultiply3] * 3,
                    pUglyNumbers[pMultiply5] * 5);
            pUglyNumbers[i] = min;
            while (pUglyNumbers[pMultiply2] * 2 <= min)
                pMultiply2++;
            while (pUglyNumbers[pMultiply3] * 3 <= min)
                pMultiply3++;
            while (pUglyNumbers[pMultiply5] * 5 <= min)
                pMultiply5++;
        }
        return pUglyNumbers[index - 1];
    }

    public static int getMin(int a, int b, int c) {
        int min = a > b ? b : a;
        return c < min ? c : min;
    }
}
