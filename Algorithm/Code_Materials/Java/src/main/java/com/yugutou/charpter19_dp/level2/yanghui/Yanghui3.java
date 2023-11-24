package com.yugutou.charpter19_dp.level2.yanghui;

import java.util.ArrayList;
import java.util.List;

/**
 * 一个数组实现
 */
public class Yanghui3 {
    public static List<Integer> generate(int rowIndex) {
        List<Integer> row = new ArrayList<Integer>();
        row.add(1);
        for (int i = 1; i <= rowIndex; ++i) {
            row.add(0);
            for (int j = i; j > 0; --j) {
                row.set(j, row.get(j) + row.get(j - 1));
            }
        }
        return row;
    }

    public static void main(String[] args) {
        List<Integer> yanghui = generate(6);
        for (int i = 0; i < yanghui.size(); i++) {
            System.out.print(yanghui.get(i) + " ");
        }
    }
}
