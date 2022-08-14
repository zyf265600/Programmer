#include <iostream>
#include <random>
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

    default_random_engine e;
    uniform_int_distribution<unsigned> u(60, 100);

    for (size_t i = 0; i < length; ++i)
    {
        teacher[i].teacherName = tName + nameSeed[i];

        for (size_t j = 0; j < 5; ++j)
        {
            teacher[i].students[j].studentName = sName + nameSeed[j];
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