package com.yugutou.charpter3_array.level1.单调数组;

/**
 *  热身专题1：判断数组元素是否有序
 * 判断数组的单调性
 * LeetCode 896.单调数列
 * 如果数组是单调递增或单调递减的，那么它是 单调 的。
 * 如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> = nums[j]，那么数组 nums 是单调递减的。
 * 当给定的数组 nums 是单调数组时返回 true，否则返回 false。
 */
public class Monotonic {
    public static void main(String[] args) {
        int a[] = {1, 2, 2, 3};
        int testMethod = 1;
//        通过两次遍历来实现
        System.out.println(isMonotonic(a));
//        一次遍历实现
        System.out.println(isMonotonic_2(a));

    }

    /**
     * 第一种方法，两次遍历确定，第一次确定是否递增 ，第二次
     *
     * @param nums
     * @return
     */
    public static boolean isMonotonic(int[] nums) {
        return isSorted(nums, true) || isSorted(nums, false);
    }

    public static boolean isSorted(int[] nums, boolean increasing) {
        int n = nums.length;
        for (int i = 0; i < n - 1; ++i) {
            if(increasing){
                if (nums[i] > nums[i + 1]) {
                    return false;
                }
            }else{
                if (nums[i] < nums[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * 第二种方式，一次遍历确定
     *如果是递增的就一定不能出现递减的相邻元素，
     * 如果出现递减的就一定不能出现递增的相邻元素。
     * @param nums
     * @return
     */
    public static boolean isMonotonic_2(int[] nums) {
        boolean inc = true, dec = true;
        int n = nums.length;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = false;
            }
            if (nums[i] < nums[i + 1]) {
                dec = false;
            }
        }
        return inc || dec;
    }
}
