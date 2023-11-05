package com.yugutou.charpter13_math.level3;

public class Gcd {
    public static void main(String[] args) {
        System.out.println(gcd1(6,15));
        System.out.println(gcd1(18,15));
    }

    /**
     *方法1： 循环实现辗转相除法
     * @param a
     * @param b
     * @return
     */
    public static int gcd1(int a, int b) {// 循环实现
        int k = 0;
        do {
            k = a % b;// 得到余数
            a = b;// 根据辗转相除法,把被除数赋给除数
            b = k;// 余数赋给被除数
        } while (k != 0);
        return a;// 返回被除数
    }

    /**
     * 方法2：递归实现辗转相除法
     * @param a
     * @param b
     * @return
     */
    public  static int gcd2(int a, int b) {
        if (b == 0) {// 直到满足此条件逆归退出
            return a;
        }
        if (a < 0) {
            return gcd2(-a, b);
        }
        if (b < 0) {
            return gcd2(a, -b);
        }
        return gcd2(b, a % b);
    }
}
