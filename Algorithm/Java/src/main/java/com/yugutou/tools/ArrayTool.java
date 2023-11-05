package com.yugutou.tools;

public class ArrayTool {
    public static void printList(String msg, int[] arr, int size) {
        System.out.println("\n通过" + msg + "打印");
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
    }

}
