package org.datatype;

import java.util.HashMap;
import java.util.Map;

public class MyMap {
    public static void main(String[] args){
        Map<String, String> map = new HashMap<>();

        map.put("0", "ok");
        map.put("1", "Hello");

        System.out.println(map.get("0"));
        System.out.println(map.get("3"));

        for (String s : map.keySet()){
            System.out.println(s);
        }

        for(String s : map.values()){
            System.out.println(s);
        }

        for (Map.Entry<String, String> m : map.entrySet()){
            System.out.println(m);
        }
    }
}
