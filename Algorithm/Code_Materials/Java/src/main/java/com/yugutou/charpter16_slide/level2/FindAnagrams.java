package com.yugutou.charpter16_slide.level2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class FindAnagrams {
    public static void main(String[] args) {
        String s = "cbaebabacd", p = "abc";
        System.out.println(findAnagrams(s, p));

    }

    public static List<Integer> findAnagrams(String s, String p) {
        int sLen = s.length(), pLen = p.length();
        if (sLen < pLen) {
            return new ArrayList<Integer>();
        }
        List<Integer> ans = new ArrayList<Integer>();
        int[] sCount = new int[26];
        int[] pCount = new int[26];
        //先分别初始化两个数组
        for (int i = 0; i < pLen; i++) {
            sCount[s.charAt(i) - 'a']++;
            pCount[p.charAt(i) - 'a']++;
        }
        if (Arrays.equals(sCount, pCount)) {
            ans.add(0);
        }

        for (int left = 0; left < sLen - pLen; left++) {
            sCount[s.charAt(left) - 'a']--;
            int right = left + pLen;
            sCount[s.charAt(right) - 'a']++;

            if (Arrays.equals(sCount, pCount)) {
                //上面left多减了一次，所以
                ans.add(left + 1);
            }
        }
        return ans;
    }
}
