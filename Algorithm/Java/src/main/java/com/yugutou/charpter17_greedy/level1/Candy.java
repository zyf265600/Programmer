package com.yugutou.charpter17_greedy.level1;

/**
 * LeetCode135：
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
 */
public class Candy {
    public static void main(String[] args) {
        int[] ratings = {1, 0, 2};
        System.out.println(candy(ratings));
    }

    public static int candy(int[] ratings) {
        int[] candyVec = new int[ratings.length];
        candyVec[0] = 1;
        for (int i = 1; i < ratings.length; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            } else {
                candyVec[i] = 1;
            }
        }
        for (int i = ratings.length - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = Math.max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        int ans = 0;
        for (int s : candyVec) {
            ans += s;
        }
        return ans;
    }
}
