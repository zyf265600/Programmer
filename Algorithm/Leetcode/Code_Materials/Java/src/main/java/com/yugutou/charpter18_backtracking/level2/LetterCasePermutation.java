package com.yugutou.charpter18_backtracking.level2;

import java.util.ArrayList;
import java.util.List;

class LetterCasePermutation {
    List<String> res = new ArrayList<>();

    //主方法
    public List<String> letterCasePermutation(String s) {
        char[] cs = s.toCharArray();
        dfs(cs, 0);
        return res;
    }

    /**
     * @param cs  搜索的字符数组
     * @param idx 开始搜索的位置
     */
    void dfs(char[] cs, int idx) {
        res.add(String.valueOf(cs));
        for (int i = idx; i < cs.length; i++) {
            // 如果是数字就跳过
            if (isDigit(cs[i]))
                continue;
            // 大小写反转
            cs[i] = changeLetter(cs[i]);
            dfs(cs, i + 1);
            // 回溯, 大小写反转回来
            cs[i] = changeLetter(cs[i]);
        }
    }

    //反转大小写
    public char changeLetter(char c) {
        return (c >= 'a' && c <= 'z') ? (char) (c - 32) : (char) (c + 32);
    }

    //判断是否是数字
    public boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    public static void main(String[] args) {
        String s = "a1b2";
        LetterCasePermutation letterCasePermutation = new LetterCasePermutation();
        System.out.println(letterCasePermutation.letterCasePermutation(s));
    }
}
