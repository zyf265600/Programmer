package com.yugutou.charpter3_array.level1.数组合并;

import java.util.Arrays;

/**
 * 合并多个一维数组
 */
public class MergeKArray {
    public static void main(String[] args) {

        //将一个多行的二维数组合并成一个一维数组，用来模拟一个待合并的多个一维数组
        int[][] twoArray = initArray();

//        执行合并多个数组的算法，每一行视为一个数组，
//        总行数视为需要合并的多个一维数组
        int[] a = mergeArrays(twoArray);

        System.out.println(Arrays.toString(a));
    }

    /**
     * 将一个多行的二维数组合并成一个一维数组，用来模拟一个待合并的多个一维数组
     *
     * @param array
     * @return
     */
    public static int[] mergeArrays(int[][] array) {
        int arrNums = array.length, arrLen;
        if (arrNums == 0) {
            return new int[0];
        }

        //数组长度校验
        arrLen = array[0].length;
        for (int i = 1; i < arrNums; i++) {
            if (arrLen != array[i].length) {
                return new int[0];
            }
        }

        //开辟新空间
        int[] result = new int[arrNums * arrLen];
        //将各个数组依次合并到一起
        for (int i = 0; i < arrNums; i++) {
            for (int j = 0; j < arrLen; j++) {
                result[i * arrLen + j] = array[i][j];
            }
        }

        //排序一下
        Arrays.sort(result);
        return result;
    }

    /**
     * 初始化一个二维数组，行数代表要合并的数组数
     *
     * @return
     */
    private static int[][] initArray() {

        //先合并到一起再排序
        int[][] twoArray = new int[4][4];
        int[] arr1 = {1, 3, 5, 6};
        int[] arr2 = {1, 2, 5, 7};
        int[] arr3 = {3, 6, 9, 11};
        int[] arr4 = {5, 7, 13, 17};

        twoArray[0] = Arrays.copyOf(arr1, 4);
        twoArray[1] = Arrays.copyOf(arr2, 4);
        twoArray[2] = Arrays.copyOf(arr3, 4);
        twoArray[3] = Arrays.copyOf(arr4, 4);
        return twoArray;
    }

}
