package com.yugutou.charpter10_quicksort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class QuickSort {
    public static void main(String[] args) {
        int[] array = {10,3,2,8,9,4,6,1};
//        int[] array = {8,4, 7,5,6,2,3,1};
        quickSort(array, 0, array.length - 1);
        System.out.println(Arrays.toString(array));
        List<Integer> list =new ArrayList<>();

    }

    private static void quickSort(int[] array, int start, int end) {
        if (start >= end) {
            return;
        }
        int left = start, right = end;
        int pivot = array[(start + end) / 2];
        while (left <= right) {
            while (left <= right && array[left] < pivot) {
                left++;
            }
            while (left <= right && array[right] > pivot) {
                right--;
            }
            if (left <= right) {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;
                left++;
                right--;

            }
        }
        quickSort(array, start, right);
        quickSort(array, left, end);
    }
}
