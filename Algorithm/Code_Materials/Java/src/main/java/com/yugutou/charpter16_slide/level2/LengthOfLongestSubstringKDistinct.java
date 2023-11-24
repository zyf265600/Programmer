package com.yugutou.charpter16_slide.level2;

import java.util.Collections;
import java.util.HashMap;

public class LengthOfLongestSubstringKDistinct {
    public static void main(String[] args) {
        String s = "eceba";
        int k = 2;
        System.out.println(lengthOfLongestSubstringKDistinct(s, k));
    }

    public static int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (s.length() < k + 1) {
            return s.length();
        }

        int left = 0, right = 0;
        HashMap<Character, Integer> hashmap = new HashMap<>();
        int maxLen = k;

        while (right < s.length()) {

            if (hashmap.size() < k + 1)
                hashmap.put(s.charAt(right), right++);

            // 如果大小达到了k个
            if (hashmap.size() == k + 1) {
                //
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
