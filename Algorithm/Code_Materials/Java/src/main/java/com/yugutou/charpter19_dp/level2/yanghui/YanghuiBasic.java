package com.yugutou.charpter19_dp.level2.yanghui;

/**
 * 根据定义实现的基本的杨辉三角
 */
public class YanghuiBasic {
    public static void main(String args[]) {
        //确定一个有10个数组（元素为数组）的二维数组
        int a[][] = new int[10][];
        //取出a[0],a[1]......a[9]十个数组
        for (int i = 0; i < a.length; i++) {
            //为10个数组确定空间（元素数目）
            a[i] = new int[i + 1];
            //将所有数组的第一个和最后一个元素元素赋值为1
            a[i][0] = 1;
            a[i][i] = 1;
        }

        //取出a[0],a[1]......a[9]十个数组
        for (int i = 0; i < a.length; i++) {

            //从第三个数组开始
            if (i > 1) {
                for (int j = 0; j < a.length; j++) {

                    //所有数组的第二个到倒数第二个元素，它们的值为前一个数组所对应的元素和前一个元素的和
                    //（a[2][1]=a[1][1]+a[1][0])
                    if (j > 0 && j < i) {
                        a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                    }
                }
            }
        }
        //通过下标访问数组的元素
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                //这里使用print不进行自动换行，使用“\t”进行跳格（tab key即为空格键)
                System.out.print(a[i][j] + "\t");
            }
            //这里每进行一次for循环，都将结果进行换行
            System.out.println();
        }
    }
}
