package com.yugutou.charpter18_backtracking.level3;

import java.util.ArrayList;
import java.util.List;

public class RestoreIpAddresses {

    static List<String> result = new ArrayList<>();

    public static void main(String[] args) {
        String s = "25525511135";

        List<String> list = restoreIpAddresses(s);
        System.out.println(list);
    }


    public static List<String> restoreIpAddresses(String s) {
        //这个是IP的特性决定的
        if (s.length() < 4 || s.length() > 12)
            return result;
        backTrack(s, 0, 0);
        return result;
    }

    // startIndex: 搜索的起始位置， pointNum:添加小数点的数量
    private static void backTrack(String s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.length() - 1)) {
                result.add(s);
            }
            return;
        }
        for (int i = startIndex; i < s.length(); i++) {
            if (isValid(s, startIndex, i)) {
                s = s.substring(0, i + 1) + "." + s.substring(i + 1);
                pointNum++;
                backTrack(s, i + 2, pointNum);
                pointNum--;// 撤销操作
                s = s.substring(0, i + 1) + s.substring(i + 2);//撤销操作
            } else {
                break;
            }
        }
    }

    // 判断字符串s在左闭⼜闭区间[start, end]所组成的数字是否合法
    private static Boolean isValid(String s, int start, int end) {
        if (start > end) {
            return false;
        }
        // 0开头的数字不合法
        if (s.charAt(start) == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            // 遇到⾮数字字符不合法
            if (s.charAt(i) > '9' || s.charAt(i) < '0') {
                return false;
            }
            num = num * 10 + (s.charAt(i) - '0');
            if (num > 255) { // 如果⼤于255了不合法
                return false;
            }
        }
        return true;
    }
}
