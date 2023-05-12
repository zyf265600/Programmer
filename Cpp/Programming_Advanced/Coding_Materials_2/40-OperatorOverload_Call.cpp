#include <iostream>
using namespace std;

//重载的调用操作符
class MyPrint
{

private:
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

//仿函数没有固定写法，非常灵活
//加法类
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};


void MyPrint02(string text)
{
    cout << text << endl;
}

//特别像 对象直接调用了函数, 只不过正常调用函数是函数名()，现在是对象名()
void test01()
{
    MyPrint mp;
    MyAdd ma;
    //由于重载后使用的方式非常像函数的调用，因此称为仿函数
    mp("Hello World!"); // mp.operator()("Hello World!")
    MyPrint02("Hello World!");
    mp(to_string(ma(1,2)));

    //匿名函数对象
    //MyAdd（）是一个匿名对象，在这一行执行完毕后就会消失
    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main()
{
    test01();
    return 0;
}