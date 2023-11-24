package com.yugutou.charpter3_array.level2.topic2_2奇偶移动;

import java.util.Arrays;

/**
 * LeetCode905，按奇偶排序数组。给定一个非负整数数组 `A`，返回一个数组，在该数组中， `A` 的所有偶数元素之后跟着所有奇数元素。
 * 你可以返回满足此条件的任何数组作为答案。
 */
public class Division {
    public static void main(String[] args) {
        int[] arr = {3, 1, 2, 4};
        int test = 1;
        if (test == 2) {
            //双指针,不稳定的方法
            System.out.println(Arrays.toString(sortArrayByParity(arr)));
        } else {
            //模仿冒泡排序，稳定的方法
            System.out.println(Arrays.toString(reOrderArray(arr)));
        }
    }

    /**
     * 双指针，不稳定 的移动
     *
     * @param A
     * @return
     */
    public static int[] sortArrayByParity(int[] A) {
        int left = 0, right = A.length - 1;
        while (left < right) {
            if (A[left] % 2 > A[right] % 2) {
                int tmp = A[left];
                A[left] = A[right];
                A[right] = tmp;
            }

            if (A[left] % 2 == 0) left++;
            if (A[right] % 2 == 1) right--;
        }

        return A;
    }

    /**
     * 模仿冒泡的稳定移动方法
     *
     * @param array
     * @return
     */
    public static int[] reOrderArray(int[] array) {
        if (array == null || array.length == 0)
            return new int[0];
        int n = array.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                // 左边是偶数, 右边是奇数的情况
                if ((array[j] & 1) == 0 && (array[j + 1] & 1) == 1) {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
        return array;
    }
}
