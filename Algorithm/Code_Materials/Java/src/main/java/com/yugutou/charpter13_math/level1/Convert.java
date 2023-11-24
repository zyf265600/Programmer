package com.yugutou.charpter13_math.level1;

public class Convert {

    public static final String[] F = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

    public static void main(String[] args) {
        System.out.println(convert(100, 7));

    }

    /**
     * 将十进制数M转化为N进制数
     *
     * @param M
     * @param N
     * @return
     */
    public static String convert(int M, int N) {
        Boolean flag = false;
        if (M < 0) {
            flag = true;
            M *= -1;
        }
        StringBuffer sb = new StringBuffer();
        int temp;
        while (M != 0) {
            temp = M % N;
            //技巧一：通过数组F[]解决了大量繁琐的不同进制之间映射的问题
            sb.append(F[temp]);
            M = M / N;
        }
        //技巧二：使用StringBuffer的reverse()方法，让原本麻烦的转置瞬间美好
        sb.reverse();
        //技巧三：最后处理正负，不要从一开始就揉在一起。
        return (flag ? "-" : "") + sb.toString();
    }
}
