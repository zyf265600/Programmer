package com.yugutou.charpter3_array.level1;


import static com.yugutou.tools.ArrayTool.printList;

/**
 * @author liuqingchao
 * @说明 在有序数组中插入新元素
 * @email 505459350@qq.com
 */
public class BasicAddByElement {
    public static void main(String[] args) {
        //初始化数组
        int[] arr = initArray();
        int size = 4;//数组中已有元素的数量

        //测试中间位置插入元素
        addByElementSequence(arr, size, 19);
        printList("通过元素顺序插入", arr, 5);

//        //在上面基础上继续测试,尾部位置插入元素
//        size = size + 1;
//        addByElementSequence(arr, size, 9);
//        printList("通过元素顺序，尾部插入", arr, 6);
//
//        //在上面基础上继续测试，首部位置插入元素
//        size = size + 1;
//        addByElementSequence(arr, size, 0);
//        printList("通过元素顺序，尾部插入", arr, 7);
    }

    /**
     * @param arr
     * @param size    数组已经存储的元素数量
     * @param element 待插入的元素元素
     * @return
     */
    public static int addByElementSequence(int[] arr, int size, int element) {
        //size和arr.length都表示元素的数量，都是从1开始编号
        if (size >= arr.length)
            throw new IllegalArgumentException("Add failed. Array is full.");
        int index = size;
        //找到新元素的插入位置
        for (int i = 0; i < size; i++) {
            if (element < arr[i]) {
                index = i;
                break;
            }
        }
        //元素后移
        for (int j = size; j > index; j--) {
            arr[j] = arr[j - 1]; //index下标开始的元素后移一个位置
        }
        arr[index] = element;//插入数据
        return index;
    }

    /**
     * 初始化要使用的数组
     * @return
     */
    private static int[] initArray() {
        int[] arr = new int[20];
        arr[0] = 3;
        arr[1] = 4;
        arr[2] = 7;
        arr[3] = 8;
        return arr;
    }

}
