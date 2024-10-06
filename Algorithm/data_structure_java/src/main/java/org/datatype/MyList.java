package org.datatype;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MyList {
    public static void main(String[] args){
        List<String> list = new ArrayList<>();
        list.add("Hello ");
        list.add("World");

        System.out.println(list.size());
//        System.out.println(list.get(0));
//        System.out.println(list.get(1));

        list.remove(1);
        list.set(0,"Ok");

        for(String s : list){
            System.out.print(s);
        }
        System.out.println();

        String[] s = list.toArray(new String[0]);

        List<Integer> ll = new LinkedList<>();
    }
}
