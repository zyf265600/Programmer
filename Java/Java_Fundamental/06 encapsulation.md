public class User {
    //1.私有化全部的成员变量
    //2.空参构造
    //3.带全部参数的构造
    //4.针对于每一个私有化的成员变量都要提供其对应的get和set方法
    //5.如果当前事物还有其他行为，那么也要写出来，比如学生的吃饭，睡觉等行为

    private String username;//用户名
    private String password;//密码
    private String email;//邮箱
    private char gender;//性别
    private int age;//年龄
    
    //空参构造方法
    public User() {
    }
    
    //带全部参数的构造
    public User(String username, String password, String email, char gender, int age) {
        this.username = username;
        this.password = password;
        this.email = email;
        this.gender = gender;
        this.age = age;
    }
    
    //get和set
    
    public String getUsername() {
        return username;
    }
    
    public void setUsername(String username) {
        this.username = username;
    }
    
    public String getPassword() {
        return password;
    }
    
    public void setPassword(String password) {
        this.password = password;
    }
    
    public String getEmail() {
        return email;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }
    
    public char getGender() {
        return gender;
    }
    
    public void setGender(char gender) {
        this.gender = gender;
    }
    
    public int getAge() {
        return age;
    }
    
    public void setAge(int age) {
        this.age = age;
    }
    
    public void eat(){
        System.out.println(username + "在吃饭");
    }
}

public class Test {
    public static void main(String[] args) {
        //写一个标准的javabean类
        //咱们在课后只要能把这个标准的javabean能自己写出来，那么就表示今天的知识点就ok了


        //利用空参构造创建对象
        User u1 = new User();
        //如果利用空参创建对象，还想赋值只能用set方法赋值
        u1.setUsername("zhangsan");
        u1.setPassword("1234qwer");
        u1.setEmail("itheima@itcast.cn");
        u1.setGender('男');
        u1.setAge(23);
        //获取属性的值并打印
        System.out.println(u1.getUsername() + ", " + u1.getPassword()
                + ", " + u1.getEmail() + ", " + u1.getGender() + ", " + u1.getAge());
        u1.eat();
    
        System.out.println("=============================");
    
        //简单的办法
        //利用带全部参数的构造来创建对象
        //快捷键:ctrl + p
        User u2 = new User("lisi","12345678","lisi@itcast.cn",'女',24);
        System.out.println(u2.getUsername() + ", " + u2.getPassword()
                + ", " + u2.getEmail() + ", " + u2.getGender() + ", " + u2.getAge());
        u2.eat();
    }
}