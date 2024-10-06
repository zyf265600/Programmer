package org.datatype;

public class MyString {
    public static void main(String[] args) {
        declare();
    }

    public static void declare(){
        String s1 = "test";
        String s2 = new String(new char[]{'t','e','s','t'});

        String s = "Hello"; // immutable
        System.out.println(s);
        s = s.toUpperCase();
        System.out.println(s);
        s = s.toLowerCase();
        System.out.println();

        System.out.println(s.contains("ll"));
        System.out.println(s.indexOf("e"));
        System.out.println(s.lastIndexOf('l'));
        System.out.println(s.startsWith("he"));
        System.out.println(s.endsWith("lo"));
        System.out.println(s.substring(2));
        System.out.println(s.substring(2,4));
        System.out.println();

        System.out.println("A,,B;C ,D".replaceAll("[,;\\s]+", ","));
        System.out.println();

        StringBuilder sb = new StringBuilder(100);
        sb.append("Hello")
                .append(" ")
                .append("World");
        System.out.println(sb);
    }
}