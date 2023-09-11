import java.util.Scanner;

public class a09_method {
    public static void main(String[] args) {
        int[] arr = {1, 3, 4, 6, 7, 9};

        Scanner sc = new Scanner(System.in);

        System.out.println("Please input index number: ");
        int number = sc.nextInt();
        int result = IndexCheck(arr, number);

        if (result == -1) System.out.println("Not found!");
        else System.out.println("Yes we found it!!! The index number is " + result);
    }

    public static int IndexCheck(int[] arr, int number){
        int result = -1;

        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] == number) result = i;
        }

        return result;
    }
}
