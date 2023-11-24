package com.yugutou.charpter3_array.level2.topic2_1删除元素;

/**
 * 原地移除所有数值等于 val 的元素
 * LeetCode27.给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。
 * 要求：不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 */
public class DeleteVal {
    public static void main(String[] args) {
        int[] arr = {3, 2, 2, 3, 3};
        int test = 2;

        if (test == 1) {//快慢指针
            System.out.println(removeElement(arr, 3));
        } else if (test==2){//标准的双指针
            System.out.println(removeElement2(arr, 2));
        }else{//优化的双指针
            System.out.println(removeElement3(arr, 3));
        }

    }

    /**
     * 方法1：使用快慢型双指针
     *
     * @param nums
     * @param val
     * @return
     */
    public static int removeElement(int[] nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.length; fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        //最后剩余元素的数量
        return slow;
    }

    /**
     * 方法2：使用对撞型双指针
     *
     * @param nums
     * @param val
     * @return
     */


    public static int removeElement2(int[] nums, int val) {

//        3, 3, 3, [], []
        int right = nums.length - 1;
        int left = 0;

        for (left = 0; left <= right; ) {
            if ((nums[left] == val) && (nums[right] != val)) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;

            }

            if (nums[left] != val) {
                left++;
            }
            if (nums[right] == val){
                right--;
            }

        }
        return left ;
    }

    /**
     * 方法三：优化对撞型双指针
     * @param nums
     * @param val
     * @return
     */
    public static int removeElement3(int[] nums, int val) {
        int right = nums.length-1;
        for (int left = 0; left < right; ) {
            if (nums[left] == val) {
                nums[left] = nums[right ];
                right--;
            } else {
                left++;
            }
        }
        return right;
    }
}
