package com.yugutou.charpter3_array.level3;

public class SortColors {
    public static void main(String[] args) {
        int[] nums = {2, 0, 2, 1, 1, 0};

    }

    public static void sortColors(int[] nums) {
        int n = nums.length;
        int left = 0;
        //将所有的0交换到数组的最前面
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                left++;
            }
        }

        //将所有的1交换到2的前面
        for (int right = left; right < n; ++right) {
            if (nums[right] == 1) {
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                ++left;
            }
        }
    }
}
