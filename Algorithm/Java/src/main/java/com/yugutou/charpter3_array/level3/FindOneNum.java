package com.yugutou.charpter3_array.level3;

import java.util.HashSet;
import java.util.Set;


public class FindOneNum {
    public static void main(String[] args) {
        int[] arr = {4, 1, 2, 1, 2};
        System.out.println(findOneNum(arr));
        System.out.println(findOneNum2(arr));
    }

    /**
     * 基于集合寻找
     * @param arr
     * @return
     */
    public static Integer findOneNum(int[] arr) {
        Set<Integer> set = new HashSet<Integer>();
        for (int i : arr) {
            if (!set.add(i))//添加不成功返回false，前加上！运算符变为true
                set.remove(i);//移除集合中与这个要添加的数重复的元素
        }
        //注意边界条件的处理
        if (set.size() == 0)
            return null;
        //如果Set集合长度为0，返回null表示没找到
        return set.toArray(new Integer[set.size()])[0];
    }

    /**
     * 基于位运算
     * @param arr
     * @return
     */
    public static int findOneNum2(int[] arr) {
        int flag = 0;
        for(int i : arr) {
            flag ^= i;
        }
        return flag;
    }
}
