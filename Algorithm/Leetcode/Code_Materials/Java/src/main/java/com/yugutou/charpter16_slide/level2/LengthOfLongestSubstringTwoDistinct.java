package com.yugutou.charpter16_slide.level2;

import java.util.Collections;
import java.util.HashMap;

public class LengthOfLongestSubstringTwoDistinct {

    public static void main(String[] args) {
        String s = "eceba";
        System.out.println(lengthOfLongestSubstringTwoDistinct(s));
    }

    public static int lengthOfLongestSubstringTwoDistinct(String s) {

        if (s.length() < 3) {
            return s.length();
        }
        int left = 0, right = 0;
        HashMap<Character, Integer> hashmap = new HashMap<>();
        int maxLen = 2;

        while (right < s.length()) {

            if (hashmap.size() < 3)
                hashmap.put(s.charAt(right), right++);

            // 如果大小达到了3个
            if (hashmap.size() == 3) {
                // 最左侧要删除的位置
                int del_idx = Collections.min(hashmap.values());
                hashmap.remove(s.charAt(del_idx));
                // 窗口left的新位置
                left = del_idx + 1;
            }

            maxLen = Math.max(maxLen, right - left);
        }
        return maxLen;
    }
}
