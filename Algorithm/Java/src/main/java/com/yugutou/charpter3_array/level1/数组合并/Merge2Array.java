package com.yugutou.charpter3_array.level1.数组合并;

import java.util.Arrays;

import static com.yugutou.tools.ArrayTool.printList;


/**
 * LeetCode88 合并两个数组
 * 要求：给你两个按非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
 * 请你合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
 *
 */
public class Merge2Array {
    public static void main(String[] args) {
        int[] arr1 = {1,2,3,0,0,0,};
        int[] arr2 = new int[]{2, 5, 6};

        int testMethod = 3;
        switch (testMethod) {
            case 1://通过排序实现合并
                merge1(arr1, 3, arr2, 3);
                break;
            case 2://基本的逐个合并
                merge2(arr1, 3, arr2, 3);
                break;
            case 3://对2的优化
                merge3(arr1, 3, arr2, 3);
                break;
        }

        printList("合并的结果为", arr1, 6);

    }

    /**
     * 方法1：先合并再排序实现排序
     *
     * @param nums1 第一个数组
     * @param nums1_len 第一个数组的长度
     * @param nums2  第二个数组，将nums2合并到nums1中
     * @param nums2_len 第二个数组的长度
     */
    public static void merge1(int[] nums1, int nums1_len, int[] nums2, int nums2_len) {
        for (int i = 0; i < nums2_len; ++i) {
            nums1[nums1_len + i] = nums2[i];
        }
        Arrays.sort(nums1);
    }

    /**
     * 方法2：两个数组从后向前逐步合并
     *
     * @param nums1
     * @param nums1_len
     * @param nums2
     * @param nums2_len
     */
    public static void merge2(int[] nums1, int nums1_len, int[] nums2, int nums2_len) {
        int i = nums1_len + nums2_len - 1;
        int len1 = nums1_len - 1, len2 = nums2_len - 1;
        while (len1 >= 0 && len2 >= 0) {
            if (nums1[len1] <= nums2[len2])
                nums1[i--] = nums2[len2--];
            else if (nums1[len1] > nums2[len2])
                nums1[i--] = nums1[len1--];
        }
        //假如A或者B数组还有剩余
        while (len2 != -1) nums1[i--] = nums2[len2--];
        while (len1 != -1) nums1[i--] = nums1[len1--];
    }

    /**
     * 方法3：优化上面的方法2
     *
     * @param nums1
     * @param nums1_len
     * @param nums2
     * @param nums2_len
     */
    public static void merge3(int[] nums1, int nums1_len, int[] nums2, int nums2_len) {
        int indexA=nums1_len-1;
        int indexB=nums2_len-1;
        int index=nums1_len+nums2_len-1;
        while (indexA>=0&&indexB>=0){
            nums1[index--]=nums1[indexA]>=nums2[indexB]?nums1[indexA--]:nums2[indexB--];
        }
        //假如A或者B数组还有剩余
        while (indexB>=0){
            nums1[index--]=nums2[indexB--];
        }
    }

}
