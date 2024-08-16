package _Stream;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class StreamMap {
    public static void main(String[] args) {
        List.of("  Apple ", " pear ", "       ORANGE      ", " BaNaNa ")
                .stream()
                .map(String::trim) // 去空格
                .map(String::toLowerCase) // 变小写
                .forEach(System.out::println); // 打印

        String[] array = { "apple", "Orange", "banana", "Lemon" };
        Arrays.sort(array, new Comparator<String>() {
            public int compare(String s1, String s2) {
                return s1.compareTo(s2);
            }
        });
    }
}
