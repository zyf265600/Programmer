

public class a06_Operator {
    private static String getType(Object a) {
        return a.getClass().toString();
    }
    public static void main(String[] args){
        int i = 10;
        long n = 100L;
        double d = 20.0;
        System.out.println(getType(i + n + d));
    }
}
