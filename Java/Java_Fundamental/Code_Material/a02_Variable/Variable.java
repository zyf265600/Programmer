package a02_Variable;

import java.util.Scanner;

public class Variable {
    public static void main(String[] args) {
        // int n = 100; // 定义变量n，同时赋值为100
        // System.out.println("n = " + n); // 打印n的值

        // n = 200; // 变量n赋值为200
        // System.out.println("n = " + n); // 打印n的值

        // int x = n; // 变量x赋值为n（n的值为200，因此赋值后x的值也是200）
        // System.out.println("x = " + x); // 打印x的值

        // x = x + 100; // 变量x赋值为x+100（x的值为200，因此赋值后x的值是200+100=300）
        // System.out.println("x = " + x); // 打印x的值
        // System.out.println("n = " + n); // 再次打印n的值，n应该是200还是300？

        Scanner scanner = new Scanner(System.in); // 创建Scanner对象
        System.out.print("Input your name: "); // 打印提示
        String name = scanner.nextLine(); // 读取一行输入并获取字符串
        System.out.print("Input your age: "); // 打印提示
        int age = scanner.nextInt(); // 读取一行输入并获取整数
        System.out.printf("Hi, %s, you are %d\n", name, age); // 格式化输出
    }
}
