package com.yugutou.charpter13_math.level1;

public class IsPalindrome {

    public static void main(String[] args) {
        System.out.println(isPalindrome(121));
        System.out.println(isPalindrome(121));
    }

    /**
     * 方法1 通过字符串实现
     *
     * @param x
     * @return
     */
    public static boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        String oldStr = "" + x;
        String newStr = new StringBuilder("" + x).reverse().toString();
        return oldStr.equals(newStr);
    }

    /**
     * 方法2：通过移位计算
     *
     * @param x
     * @return
     */
    public static boolean isPalindrome2(int x) {
        if (x < 0) {
            return false;
        }
        long ans = 0;
        int old = x;
        while (x > 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans == old;
    }

}
