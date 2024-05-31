import java.util.Random;
import java.util.Scanner;

public class a07_random_number {
    public static void main(String[] args) {

        Random r = new Random ();
        int rn = r.nextInt(100); // 0~99

        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();

        while(input != rn){
            if (input > rn) System.out.println("Too much!");
            else if (input < rn) System.out.println("Too small!");
            input = sc.nextInt();
        }

        sc.close();
        System.out.println("You got it!!!");
    }
}
