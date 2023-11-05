package com.yugutou.charpter10_quicksort;

import java.util.Arrays;

/**
 *
 */
public class QuickSortBasic {
    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 3, 7, 6, 1, 8, 4};
        quickSort(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
    }

    public static void quickSort(int[] arr, int left, int right) {
        if (left < right) {
            int pivot = arr[right];
            int i = left - 1;
            for (int j = left; j < right; j++) {
                if (arr[j] < pivot) {
                    i++;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            //哨兵移动到位置pivotIndex上
            int pivotIndex = i + 1;
            int temp = arr[pivotIndex];
            arr[pivotIndex] = arr[right];
            arr[right] = temp;

            quickSort(arr, left, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, right);
        }
    }


}
