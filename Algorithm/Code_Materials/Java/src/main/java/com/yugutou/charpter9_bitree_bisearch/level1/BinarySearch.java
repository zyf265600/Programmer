package com.yugutou.charpter9_bitree_bisearch.level1;

public class BinarySearch {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int result = -1;
        int testMethod = 1;
        switch (testMethod) {
            case 1:
                result = binarySearch1(array, 0, 8, 5);
                break;
            case 2:
                result = binarySearch2(array, 0, 8, 3);
                break;

        }
        System.out.println(result);


    }

    /**
     * 循环实现二分查找
     *
     * @param array
     * @param low
     * @param high
     * @param target
     * @return
     */
    public static int binarySearch1(int[] array, int low, int high, int target) {

        // 循环
        while (low <= high) {

            int mid = (low + high) / 2;
//1.右移提高性能
            if (array[mid] == target) {
                return mid;
            } else if (array[mid] > target) {
                // 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
                high = mid - 1;
            } else {
                // 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
                low = mid + 1;
            }
        }
        return -1;
    }

    /**
     * 方法二：递归方式实现
     *
     * @param array
     * @param low
     * @param high
     * @param target
     * @return
     */
    public static int binarySearch2(int[] array, int low, int high, int target) {
        //递归终止条件
        if (low < high) {
            int mid = (low + high) >> 1;
//            int mid=low +(high-low)>>1;
            if (array[mid] == target) {
                return mid;  // 返回目标值的位置，从1开始
            }
            if (array[mid] > target) {
                // 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
                return binarySearch2(array, low, mid - 1, target);
            } else {
                // 由于array[mid]不是目标值，因此再次递归搜索时，可以将其排除
                return binarySearch2(array, mid + 1, high, target);
            }
        }
        return -1;   //表示没有搜索到
    }
}
