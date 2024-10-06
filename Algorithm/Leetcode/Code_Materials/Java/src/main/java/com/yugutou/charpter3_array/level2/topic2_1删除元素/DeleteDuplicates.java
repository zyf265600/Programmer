package com.yugutou.charpter3_array.level2.topic2_1删除元素;

/**
 * 删除重复元素，重复只保留一个
 */
public class DeleteDuplicates {
    public static void main(String[] args) {
        int[] arr = new int[]{1, 2,3,3,4,4,5 };
        int last = removeDuplicates(arr);
        for (int i = 0; i < last; i++) {
            System.out.print(arr[i] + "  ");
        }
    }

    public static int removeDuplicates(int[] nums) {
        //slow表示可以放入新元素的位置，索引为0的元素不用管
        int slow = 0;
        //循环起到了快指针的作用
        for (int fast = 0; fast < nums.length; fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];

            }
        }
        return slow+1;
    }

    public static int deleteRepeatVal(int[] nums) {
        int slow = 0;
        int fast = 1;
        while (fast < nums.length) {
            if (nums[slow] == nums[fast]) {
                fast++;
            } else {
                nums[++slow] = nums[fast++];
            }

        }
        return slow;
    }

}
