

public class a06_operator {
    private static String getType(Object a) {
        return a.getClass().toString();
    }

    public static void main(String[] args) {
        int i = 10;
        long n = 100L;
        double d = 20.0;
        System.out.println("Type result: ");
        System.out.println(getType(i + n + d));

        int a = 13; // 二进制表示为 1101
        int b = 11; // 二进制表示为 1011
        int result = a & b; // 结果为 1，二进制表示为 1001 = 9
        System.out.println("Logic operator result: ");
        System.out.println(result);

        a = 60;  // 二进制表示为 0011 1100
        b = ~a;  // 二进制表示为 1100 0011 = -61
        System.out.println("Operator ~ result: ");
        System.out.println(b);
    }
}
