package com.yugutou.charpter9_bitree_bisearch.level2;

/**
 * LeetCode852.山峰数组，
 * 在数组中的某位位置i开始，从0到i是递增的，从i+1 到数组最后是递减的，让你找到这个最高点。
 */
public class PeakIndexInMountainArray {
    public static void main(String[] args) {
        int[] arr = {0, 1, 0};
        System.out.println(peakIndexInMountainArray(arr));
    }

    public static int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        int ans = -1;
        for (int i = 1; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
}
