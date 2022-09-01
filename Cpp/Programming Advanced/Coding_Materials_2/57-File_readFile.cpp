#include <iostream>
#include <fstream>
using namespace std;

//文本文件 读文件

void test01()
{
    // 1.包含头文件
    // #include <fstream>

    // 2.创建文件对象
    ifstream reader;

    // 3.打开文件并判断是否打开成功
    reader.open("56-File_writeFile_testFile.txt", ios::in);

    if (reader.is_open())
    {
        cout << "文件成功打开！" << endl;
    }
    else
    {
        cout << "文件打开失败！" << endl;
        return;
    }

    // 4.读数据

    // 第一种方法
    // char buf[1024] = {0};
    // while (reader >> buf)
    // {
    //     cout << buf << endl;
    // }

    // 第二种方法
    // char buf[1024] = {0};
    // while (reader.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
 
    // 第三种方法
    // string buf;
    // while (getline(reader, buf))
    // {
    // 	cout << buf << endl;
    // }

    // 第四种方法(不推荐)
    char c;
    while ( (c = reader.get()) != EOF) // EOF: end of file
    {
        cout << c;
    }
    

    // 5.关闭文件
    reader.close();
}

int main()
{
    test01();
    return 0;
}