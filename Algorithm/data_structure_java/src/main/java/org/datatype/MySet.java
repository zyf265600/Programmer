package org.datatype;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class MySet {
    public static void main(String[] args){
        Set<String> set = new HashSet<>();

        set.add("ok");
        set.add("hello");
        set.add("world");

        set.remove("ok");

        System.out.println(set.size());
        System.out.println(set.contains("ok"));
        System.out.println(set.contains("hello"));

        Set<String> sset = new TreeSet<>();

        sset.add("1");
        sset.add("2");
        sset.add("0");

        // default sorted
        for (String s : sset){
            System.out.println(s);
        }

    }
}
