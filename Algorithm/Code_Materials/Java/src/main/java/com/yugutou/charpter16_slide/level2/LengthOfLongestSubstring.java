package com.yugutou.charpter16_slide.level2;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class LengthOfLongestSubstring {
    public static void main(String[] args) {

        String s = "aabbbccdeebcss";
//        String s = "au";
//        String s = " ";
        System.out.println(lengthOfLongestSubstring(s));

    }

    public static int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int max = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            if (map.containsKey(s.charAt(right))) {
                left = Math.max(left, map.get(s.charAt(right))+1);
            }
            map.put(s.charAt(right), right);
            max = Math.max(max, right - left + 1);
        }
        return max;
    }

    public static int lengthOfLongestSubstring2(String s) {
        if (s.length() <= 1) {
            return s.length();
        }
        // 集合中的元素一定不重复，适合记录窗口内每个字符是否出现过，
        Set<Character> set = new HashSet<Character>();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int right = -1, max = 0;
        for (int left = 0; left < s.length(); left++) {
            // 左指针向右移动时移除前一个位置的字符，因此要排除left=0的情况
            if (left != 0) {
                set.remove(s.charAt(left - 1));
            }
            while (right + 1 < s.length() && !set.contains(s.charAt(right + 1))) {
                // 不断地移动右指针
                set.add(s.charAt(right + 1));
                right++;
            }
            max = Math.max(max, right - left + 1);
        }
        return max;

    }


}
