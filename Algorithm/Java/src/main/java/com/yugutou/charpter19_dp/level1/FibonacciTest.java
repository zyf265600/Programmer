package com.yugutou.charpter19_dp.level1;

/**
 * 通过斐波那契数列来感受已记忆化搜索
 */
public class FibonacciTest {
    public static int count_1 = 0;
    public static int count_2 = 0;
    public static int count_3 = 0;
    public static int[] arr = new int[50];

    public static void main(String[] args) {

        int result = fibonacci(10);
        System.out.println("count:" + count_1 + "   result: " + result);
        count_1 = 0;
        int result2 = fibonacci(20);
        System.out.println("count:" + count_1 + "   result: " + result2);

        count_1 = 0;
        int result3 = fibonacci(30);
        System.out.println("count:" + count_1 + "   result: " + result3);
        count_1 = 0;
        int result4 = fibonacci(31);
        System.out.println("count:" + count_1 + "   result: " + result4);

    }

    /**
     * 递归实现斐波那契数列
     *
     * @param n
     * @return
     */
    public static int fibonacci(int n) {
        System.out.println("我爱你");
        count_1++;
        if (n == 0) {
            return 1;
        }
        if (n == 1 || n == 2)
            return n;
        else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    /**
     * 方法2，直接累加实现斐波那契
     */
    public static int fibonacci_2(int n) {
        if (n <= 2) {
            count_2++;
            return n;
        }

        int f1 = 1;
        int f2 = 2;
        int sum = 0;
        for (int i = 3; i <= n; i++) {
            count_2++;
            sum = f1 + f2;
            f1 = f2;
            f2 = sum;
        }
        return sum;
    }

    /**
     * 方法3：借助数组临时缓存
     */
    // 我们实现假定 arr 数组已经初始化好的了。
    public static int fibonacci_3(int n) {
        if (n == 2 || n == 1) {
            count_3++;
            arr[n] = n;
            return n;
        }

        if (arr[n] != -1) {
            count_3++;
            return arr[n];
        } else {
            count_3++;
            arr[n] = fibonacci_3(n - 1) + fibonacci_3(n - 2);
            return arr[n];
        }
    }
}