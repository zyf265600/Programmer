#include <iostream>
#include <fstream> //包含头文件
using namespace std;

//文本文件 写文件

void test01()
{
    // 1. 包含头文件
    //#include <fstream>

    // 2. 创建流对象
    ofstream newFile;

    // 3. 指定打开方式
    newFile.open("56-File_writeFile_testFile.txt", ios::out);

    // 4. 写文件内容
    newFile << "姓名：张三" << endl;
	newFile << "性别：男" << endl;
	newFile << "年龄：18" << endl;

    // 5. 关闭文件
    newFile.close();
}

int main()
{
    test01();
    return 0;
}