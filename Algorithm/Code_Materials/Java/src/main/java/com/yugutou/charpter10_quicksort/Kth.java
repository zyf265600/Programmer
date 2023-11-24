package com.yugutou.charpter10_quicksort;

public class Kth {
    public static void main(String[] args) {
        int[] array = {6, 3, 2, 4, 5, 8, 7};
//        int[] array = {3, 2, 1, 5, 6, 4};
        int k = 2;//找第二大元素
        quicksort(array, 0, array.length - 1);
        System.out.println(array[k - 1]);  //因为是从零开始所以k-1;

    }

    public static void quicksort(int[] nums, int left, int right) {
        int start = left;
        int end = right;
        int pivot = nums[(end + start) / 2]; //取中位值作左右参考对比

        //每次循环都将大的放到左边，小的放到右边
        while (start < end) {
            while (nums[start] > pivot) {
                start++;
            }
            while (nums[end] < pivot) {
                end--;
            }
            //如果l>=r说明mid左边的值全部大于等于mid的值，右边全是小的，退出
            if (start >= end) {
                break;
            }
            //交换
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            //解决值相同的情况，如果交换后发现左边的值等于mid目标值，则使右边指针向左移
            if (nums[start] == pivot) {
                end--;
            }
            //右边的值等于mid目标值，则使左边指针向左移
            if (nums[end] == pivot) {
                start++;
            }
        }

        if (start == end) { //退出循环防止栈溢出
            start++;
            end--;
        }
        if (left < end) {
            quicksort(nums, left, end);   //向左递归
        }
        if (right > start) {
            quicksort(nums, start, right); //向右递归
        }
    }
}
