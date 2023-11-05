package com.yugutou.charpter19_dp.level2.yanghui;

import java.util.ArrayList;
import java.util.List;

/**
 * 滚动数组优化
 */
public class Yanghui2 {

    public static void main(String[] args) {
        List<Integer> list = getRow(5);
        System.out.println(list);
    }

    public static List<Integer> getRow(int rowIndex) {
        List<Integer> pre = new ArrayList<Integer>();
        for (int i = 0; i <= rowIndex; ++i) {
            List<Integer> cur = new ArrayList<Integer>();
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    cur.add(1);
                } else {
                    cur.add(pre.get(j - 1) + pre.get(j));
                }
            }
            pre = cur;
        }
        return pre;
    }
}
