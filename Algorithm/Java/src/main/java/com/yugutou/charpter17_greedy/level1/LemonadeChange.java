package com.yugutou.charpter17_greedy.level1;

/**
 * LeetCode860，
 * 在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
 * 顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
 */
public class LemonadeChange {
    public static void main(String[] args) {
        int[] bills = {5, 5, 10, 10, 20};
        System.out.println(lemonadeChange(bills));
    }

    public static boolean lemonadeChange(int[] bills) {
//这里只表示5元和10元纸币的数量，而不是总金额
        int cash_5 = 0;
        int cash_10 = 0;
        for (int i = 0; i < bills.length; i++) {
            if (bills[i] == 5) {
                cash_5++;
            } else if (bills[i] == 10) {
                cash_5--;
                cash_10++;
            } else if (bills[i] == 20) {
                if (cash_10 > 0) {
                    cash_10--;
                    cash_5--;
                } else {
                    cash_5 -= 3;
                }
            }
            if (cash_5 < 0 || cash_10 < 0) return false;
        }
        return true;
    }
}
