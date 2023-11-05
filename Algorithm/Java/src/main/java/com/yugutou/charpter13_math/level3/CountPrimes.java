package com.yugutou.charpter13_math.level3;

import java.util.Arrays;

public class CountPrimes {

    public static void main(String[] args) {
        System.out.println(countPrimes(10));
        System.out.println(countPrimes2(10));
    }

    /**
     * 方法1：一个个的算是不是素数
     *
     * @param n
     * @return
     */
    public static int countPrimes(int n) {
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i)) {
                cnt++;
            }
        }
        return cnt;
    }

    public static boolean isPrime(int num) {
        int max = (int) Math.sqrt(num);
        for (int i = 2; i <= max; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * 方法2：埃氏筛
     */

    public static int countPrimes2(int n) {
        int[] isPrime = new int[n];
        Arrays.fill(isPrime, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i] == 1) {
                ans += 1;
                if ((long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
}
