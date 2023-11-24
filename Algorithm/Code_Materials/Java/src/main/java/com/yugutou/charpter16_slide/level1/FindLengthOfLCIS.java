package com.yugutou.charpter16_slide.level1;

public class FindLengthOfLCIS {
    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 4, 7, 8, 9, 2};
        System.out.println(findLengthOfLCIS_1(nums));
        System.out.println(findLengthOfLCIS_2(nums));
    }

    public static int findLengthOfLCIS_1(int[] nums) {
        int left = 0, right = 0;
        int res = 0;
        while (right < nums.length) {
            //右侧的新元素比左侧的小，则重新开始记录left位置
            //该问题本质就是快慢指针，left就是slow指针
            if (right > 0 && nums[right - 1] >= nums[right]) {
                left = right;
            }
            right++;
            res = Math.max(res, right - left);
        }
        return res;
    }

    public static int findLengthOfLCIS_2(int[] nums) {
        int curLen = 1;//当前连续递增区间的长度
        int res = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] >= nums[i]) {
                //不满足要求，重新开始计数
                curLen = 1;
            } else {
                curLen++;
            }
            res = Math.max(curLen, res);
        }
        return res;
    }
}
