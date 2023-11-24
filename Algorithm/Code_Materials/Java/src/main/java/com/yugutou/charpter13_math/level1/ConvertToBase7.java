package com.yugutou.charpter13_math.level1;

public class ConvertToBase7 {
    public static void main(String[] args) {

        System.out.println(convertToBase7(100));
    }

    public static String convertToBase7(int num) {
        StringBuilder sb = new StringBuilder();
        //先拿到正负号
        boolean sign = num < 0;
        //这样预处理一下，后面都按照正数处理num就行了
        if (sign)
            num *= -1;
        //循环取余和整除
        do {
            sb.append(num % 7 + "");
            num /= 7;
        } while (num > 0);
        //添加符号
        if (sign)
            sb.append("-");
        //上面的结果是逐个在末尾加的，需要反过来
        return sb.reverse().toString();
    }
}

