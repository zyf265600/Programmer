package com.yugutou.charpter3_array.level3;

import java.util.HashMap;
import java.util.Map;

/**
 *  数组中只出现一次的数字
 *  剑指offer题目，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 */
public class MoreThanHalfNum {
    public static void main(String[] args) {
//        int[] arr = {1, 2, 3, 2, 2, 2, 5, 4, 2};
        int[] arr = {1, 2, 3, 4};
        System.out.println(majorityElement(arr));
    }

    /**
     * 方法1 基于Hash
     * @param array
     * @return
     */
    public static int moreThanHalfNum(int[] array) {
        if (array == null)
            return 0;
        Map<Integer, Integer> res = new HashMap<>();
        int len = array.length;
        for (int i = 0; i < array.length; i++) {
            res.put(array[i], res.getOrDefault(array[i], 0) + 1);
            if (res.get(array[i]) > len / 2)
                return array[i];
        }
        return 0;
    }

    /**
     * 方法二：比较特殊的计数法
     * @param array
     * @return
     */
    public static int moreThanHalfNum2(int [] array) {
        if(array==null||array.length==0)
            return 0;
        int len = array.length;
        int result=array[0];
        int times=1;
        for(int i=1;i<len;i++){
            if(times==0){
                result=array[i];
                times=1;
                continue;
            }

            if(array[i]==result)
                times++;
            else
                times--;
        }
        times=0;
        for(int i=0;i<len;i++){
            if(array[i]==result)
                times++;
            if(times>len/2)
                return result;
        }
        return 0;
    }
    public static int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
}
