package _Array;

import java.util.Arrays;

public class Array {

    public static void main(String[] args) {
        int[] ns = { 1, 1, 2, 3, 5, 8 };
        System.out.println(Arrays.toString(ns));

        for (int n : ns) {
            System.out.print(n + ", ");
        }

        System.out.println("\n" + ns);
    }

}
