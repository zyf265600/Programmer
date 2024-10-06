package com.yugutou.charpter13_math.level1;

public class Reverse {
    public static void main(String[] args) {
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Math.pow(2,31)-1);
        System.out.println(2^30-1);
//        System.out.println(reverse(432));
    }
    public static int reverse(int x) {
        int res = 0;
        while(x!=0) {
            //获得末尾数字
            int tmp = x%10;
            //判断是否大于最大32位整数，也可以使用Integer.MAX_VALUE/10来代替214748364
            if (res>214748364 || (res==214748364 && tmp>7)) {
                return 0;
            }
            //判断是否小于最小的32位整数
            if (res<-214748364 || (res==-214748364 && tmp<-8)) {
                return 0;
            }
            res = res*10 + tmp;
            x /= 10;
        }
        return res;
    }
}
