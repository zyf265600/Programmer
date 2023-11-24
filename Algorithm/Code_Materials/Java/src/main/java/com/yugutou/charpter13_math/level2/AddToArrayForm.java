package com.yugutou.charpter13_math.level2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AddToArrayForm {
    public static void main(String[] args) {
        int[] arr = {1, 2, 0, 0};
        int k = 34;
        List<Integer> result = addToArrayForm(arr, k);
        System.out.println(result.toString());
    }

    /**
     * 两个数相加
     * @param num
     * @param k
     * @return
     */
    public static List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> res = new ArrayList<Integer>();
        int n = num.length;
        for (int i = n - 1; i >= 0; --i) {
            int sum = num[i] + k % 10;
            k /= 10;
            if (sum >= 10) {
                k++;
                sum -= 10;
            }
            res.add(sum);
        }
        for (; k > 0; k /= 10) {
            res.add(k % 10);
        }
        Collections.reverse(res);
        return res;
    }
}
