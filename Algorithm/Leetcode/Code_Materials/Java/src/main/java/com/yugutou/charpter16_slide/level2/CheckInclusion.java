package com.yugutou.charpter16_slide.level2;

import java.util.Arrays;

public class CheckInclusion {
    public static void main(String[] args) {
        String s1 = "ab", s2 = "eidbaooo";
        System.out.println(checkInclusion(s1, s2));
    }

    public static boolean checkInclusion(String s1, String s2) {
        int sLen1 = s1.length(), sLen2 = s2.length();
        if (sLen1 > sLen2) {
            return false;
        }
        int[] charArray1 = new int[26];
        int[] charArray2 = new int[26];
        //先读最前面的一段来判断。
        for (int i = 0; i < sLen1; ++i) {
            ++charArray1[s1.charAt(i) - 'a'];
            ++charArray2[s2.charAt(i) - 'a'];
        }

        if (Arrays.equals(charArray1, charArray2)) {
            return true;
        }
        for (int right = sLen1; right < sLen2; ++right) {
            charArray2[s2.charAt(right) - 'a']++;
            int left = right - sLen1;
            charArray2[s2.charAt(left) - 'a']--;
            if (Arrays.equals(charArray1, charArray2)) {
                return true;
            }
        }
        return false;
    }
}
