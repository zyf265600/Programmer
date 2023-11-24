package com.yugutou.charpter17_greedy.level3;

/**
 * LeetCode45 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 假设一定能到达末尾，然后让你求最少到达的步数该怎么办呢？
 */
public class Jump {
    public static void main(String[] args) {
        int[] nums = {2, 3, 1, 1, 4};
        System.out.println(jump(nums));
    }

    public static int jump(int[] nums) {
        int right = 0;
        int maxPosition = 0;
        int steps = 0;
        for (int left = 0; left < nums.length - 1; left++) {
            //找能跳的最远的
            maxPosition = Math.max(maxPosition, nums[left] + left);
            if (left == right) { //遇到边界，就更新边界，并且步数加一
                right = maxPosition;
                steps++;
            }
            //right指针到达末尾了。
            if (right >= nums.length - 1) {
                return steps;
            }
        }
        return steps;
    }
}
