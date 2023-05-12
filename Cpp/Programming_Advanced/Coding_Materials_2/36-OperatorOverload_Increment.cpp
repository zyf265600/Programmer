#include <iostream>
using namespace std;

//重载递增运算符
class MyInteger
{
    //全局函数友元
    friend ostream &operator<<(ostream &cout, MyInteger myint);

private:
    int m_Num;

public:
    MyInteger()
    {
        m_Num = 0;
    }

    //重载 前置递增 ++increment 运算符
    MyInteger &operator++() //这里返回引用是因为要确保始终对同一个对象进行操作，返回 值 会重新构造一个全新的对象，丢失之前的操作
    {
        //先++运算
        ++m_Num;
        //再将自身返回
        return *this;
    }

    // 重载 后置递增 increment++ 运算符
    // operator++(int) int 代表占位参数，可以用于区分前置和后置递增
    // 这个是设计问题，即标准规定，得问当时的设计师怎么想的了，加形参就是为了进行区别
    MyInteger operator++(int) //这里必须返回 值，不能返回引用，如果返回引用，temp对象在函数结束后消亡，会出错
    {
        //先记录递增前的数值
        MyInteger temp = *this;
        //再递增
        ++m_Num;
        //最后将记录结果作返回
        return temp;
    }
};

//重载左移运算符
ostream &operator<<(ostream &cout, MyInteger myint) //在这里不能用 &myint，后置递增返回的是临时对象，不可以进行引用传递
{
    cout << myint.m_Num;
    return cout;
}

void test01()
{
    MyInteger myint;

    cout << ++(++myint) << endl; // myint.operator++()
    cout << myint << endl;       //如果在重载函数中只返回 值 这里的myint就会是 1 而不是期待的 2
}

void test02()
{
    MyInteger myint;
    //不需要考虑（myint++）++的情况，因为 (a++)++ 本身就是非法的, a++这种形式在C和C++中都不能作左值
    //另外特别注意 ++i在C中不是左值，在C++中才是。
    //在C语言中像 int i=0,a=2,b=3;++i=a+b;这个表达式是非法的。i++在C和C++中都不能作左值
    //具体可看 https://www.zhihu.com/question/529978814/answer/2459079068

    cout << myint++ << endl; // myint.operator++(int)
    cout << myint << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}