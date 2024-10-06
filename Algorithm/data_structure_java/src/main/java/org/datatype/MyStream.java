package org.datatype;

import java.math.BigInteger;
import java.util.stream.Stream;

public class MyStream {
    public static void main(String[] args){
        Stream<Integer> stream = Stream.of(1,3,5,7);
        stream.forEach(
                System.out::println
        );

        System.out.println();

        Stream<Integer> stream2 = Stream.of(1,3,5,7);
        stream2.map(i->i*5)
                .limit(3)
                .filter(i -> i>5)
                .forEach(System.out::println);

    }
}
