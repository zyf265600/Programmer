package com.yugutou.charpter16_slide.level1;

public class FindMaxAverage {
    public static void main(String[] args) {

        int[] num = {1, 12, -5, -6, 50, 3};
        System.out.println(findMaxAverage(num, 4));
    }

    public static double findMaxAverage(int[] nums, int k) {
        int len = nums.length;
        int widowSum = 0;
        if (k > nums.length || nums.length < 1 || k < 1) {
            return 0;
        }
        //   第一步 先求第一个窗口的和
        for (int i = 0; i < k; i++) {
            widowSum += nums[i];
        }

        //  第二步 ：遍历，每次右边增加一个，左边减去一个，重新计算窗口最大值
        int res = widowSum;
        for (int right = k; right < len; right++) {
            widowSum += nums[right] - nums[right - k];
            res = Math.max(res, widowSum);
        }
        return (double) res / k;
    }
}
