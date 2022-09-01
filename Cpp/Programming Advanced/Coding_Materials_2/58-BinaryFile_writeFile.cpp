#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_Name[64]; //姓名
    int m_Age;       //年龄
};

//二进制文件  写文件
void test01()
{
    // 1、包含头文件

    // 2、创建输出流对象
    ofstream ofs("58-person.txt", ios::out | ios::binary); //构造函数

    // 3、打开文件
    // ofs.open("person.txt", ios::out | ios::binary);

    // 4、写文件 - write 函数
    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person)); //注意要强转数据类型

    // 5、关闭文件
    ofs.close();
}

int main()
{
    test01();
    return 0;
}