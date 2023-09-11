import java.util.Scanner;
import java.util.Random;

public class a10_method_exercise {
    public static void main(String[] args) {
        System.out.println("==========================");
        System.out.println("Welcome to Lotto Game!");
        int[] lucky_num = lucky_num_generator();


        System.out.println("Please input your selected number 1~33*6 1~16*1: ");
        int[] s_num = new int[8];
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 7; i++) {
            System.out.println("Blue " + (i+1));
            s_num[i] = sc.nextInt();
        }
        System.out.println("Red 1");
        s_num[7] = sc.nextInt();
        System.out.println("==========================");

        System.out.print("The Lucky Number is: ");
        for (int i = 0; i < 7; i++) System.out.print(lucky_num[i] + " ");
        System.out.println("+ " + lucky_num[7]);

        System.out.println("==========================");
        int blue_1 = 0, red_6 = 0;
        for (int i = 0; i < 7; i++) {
            if (s_num[i] == lucky_num[i]) red_6++;
        }
        if (s_num[7] == lucky_num[7]) blue_1++;

        if (red_6 == 6 && blue_1 == 1) {
            System.out.println("Congratulations, you've won $10,000,000");
        } else if (red_6 == 6 && blue_1 == 0) {
            System.out.println("Congratulations, you've won $5,000,000");
        } else if (red_6 == 5 && blue_1 == 1) {
            System.out.println("Congratulations, you've won $3,000");
        } else if ((red_6 == 5 && blue_1 == 0) || (red_6 == 4 && blue_1 == 1)) {
            System.out.println("Congratulations, you've won $200");
        } else if ((red_6 == 4 && blue_1 == 0) || (red_6 == 3 && blue_1 == 1)) {
            System.out.println("Congratulations, you've won $10");
        } else if ((red_6 == 2 && blue_1 == 1) || (red_6 == 1 && blue_1 == 1) || (red_6 == 0 && blue_1 == 1)) {
            System.out.println("Congratulations, you've won $5");
        } else {
            System.out.println("Sorry, maybe next time~");
        }
    }


    public static int[] lucky_num_generator() {
        int[] ln = new int[]{0, 0, 0, 0, 0, 0, 0, 0};

        Random rand = new Random();

        for (int i = 0; i < 7; i++) {
            int temp = rand.nextInt(33) + 1;
            while (check(ln, temp)) temp = rand.nextInt(33) + 1;
            ln[i] = temp;
        }

        ln[7] = rand.nextInt(16) + 1;

        return ln;
    }

    public static boolean check(int[] arr, int num) {

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) return true;
        }
        return false;
    }
}
