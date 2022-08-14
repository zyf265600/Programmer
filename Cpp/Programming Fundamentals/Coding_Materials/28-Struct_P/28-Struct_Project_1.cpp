#include <iostream>
#include <random>
#include <ctime>
using namespace std;

struct student
{
    string studentName;
    int score;
};

struct teacher
{
    string teacherName;
    struct student students[5];
};

void assignName(teacher teacher[], int length)
{
    string tName = "教师";
    string sName = "学生";
    string nameSeed = "ABCDE";

    default_random_engine e(time(NULL));           // time (NULL) 为随机数种子 // 生成无符号随机整数
    uniform_int_distribution<unsigned> u(60, 100); //闭区间

    for (size_t i = 0; i < length; ++i)
    {
        teacher[i].teacherName = tName + nameSeed[i];

        for (size_t j = 0; j < 5; ++j)
        {
            teacher[i].students[j].studentName = sName + nameSeed[j];
            // 将 u 作为随机数源
            // 每个调用返回在指定范围内并服从均匀分布的值
            teacher[i].students[j].score = u(e);
        }
    }
}

void print(teacher teacher[], int length)
{
    for (size_t i = 0; i < length; ++i)
    {
        cout << "教师姓名：" << teacher[i].teacherName << "\n负责学生：" << endl;

        for (size_t j = 0; j < 5; ++j)
        {
            cout << teacher[i].students[j].studentName << "\t学生分数：" << teacher[i].students[j].score << endl;
        }
    }
}

int main()
{
    teacher teachers[3];

    int size = sizeof(teachers) / sizeof(teachers[0]);

    assignName(teachers, size);
    print(teachers, size);

    return 0;
}