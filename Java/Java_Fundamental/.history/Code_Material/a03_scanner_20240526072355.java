//1.导包，其实就是先找到Scanner这个类在哪

import java.util.Scanner;

public class a03_scanner {
    public static void main(String[] args) {
        //2.创建对象，其实就是申明一下，我准备开始用Scanner这个类了。
        Scanner sc = new Scanner(System.in);
        //3.接收数据
        //当程序运行之后，我们在键盘输入的数据就会被变量i给接收了
        System.out.println("请输入一个数字");
        int i = sc.nextInt();
        System.out.println("The number you input is: " + i);
        sc.
    }
}
