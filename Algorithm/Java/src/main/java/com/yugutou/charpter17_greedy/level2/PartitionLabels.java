package com.yugutou.charpter17_greedy.level2;

import java.util.LinkedList;
import java.util.List;

public class PartitionLabels {
    public static void main(String[] args) {
        String s = "ababcbzacadefegdehijhklij";
        List<Integer> list = partitionLabels(s);
        System.out.println(list);
    }

    public static List<Integer> partitionLabels(String S) {
        List<Integer> list = new LinkedList<>();
        int[] edge = new int[26];
        char[] chars = S.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            edge[chars[i] - 'a'] = i;
        }
        int idx = 0;
        int last = -1;
        for (int i = 0; i < chars.length; i++) {
            idx = Math.max(idx, edge[chars[i] - 'a']);
            if (i == idx) {
                list.add(i - last);
                last = i;
            }
        }
        return list;
    }
}
