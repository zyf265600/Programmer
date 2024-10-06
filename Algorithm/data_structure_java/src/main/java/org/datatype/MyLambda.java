package org.datatype;

import java.util.Arrays;

public class MyLambda {
    public static void main(String[] args) {
        String[] s = new String[]{"Apple", "Orange", "Banana", "Lemon"};
        Arrays.sort(s, MyLambda::compare);
        System.out.println(Arrays.toString(s));
    }

    static int compare(String s1,  String s2){
        return s1.compareTo(s2);
    }
}
