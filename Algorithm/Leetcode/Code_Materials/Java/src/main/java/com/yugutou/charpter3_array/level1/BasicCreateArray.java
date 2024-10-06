package com.yugutou.charpter3_array.level1;


/**
 * @author liuqingchao
 * @说明 测试数组创建和初始化
 * @email 505459350@qq.com
 */

public class BasicCreateArray {
    public static void main(String[] args) {
        //第一种创建和初始化的方法
        int[] arr = new int[10];
        for (int i = 0; i < 4; i++)
            arr[i] = i+3;
        System.out.println("arr1 size:" + arr.length);

//        //第二种创建和初始化的方法
//        int[] arr2 = new int[]{0, 1, 2, 3, 5, 6, 8};
//        System.out.println("arr2:" + Arrays.toString(arr2));
//
//        //第二种方式的简化版本:
//        int[] arr3 = {2, 5, 0, 4, 6, -10};
//        System.out.println("arr3" + Arrays.toString(arr3));


    }
}
