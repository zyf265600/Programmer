#include <iostream>
using namespace std;

struct hero
{
  string name;
  int age;
  string gender;
};

void BubbleSort(hero heroes[], int length)
{

  for (size_t i = 0; i < length; ++i)
  {
    for (size_t j = 0; j < length - i - 1; ++j)
    {
      if (heroes[j].age > heroes[j + 1].age)
      {
        hero temp;
        temp = heroes[j + 1];
        heroes[j + 1] = heroes[j];
        heroes[j] = temp;
      }
    }
  }
}

void print(hero heroes[], int length)
{
  for (size_t i = 0; i < length; ++i)
  {
    cout << "英雄：" << heroes[i].name << "\t年龄：" << heroes[i].age << "\t性别：" << heroes[i].gender << endl;
  }
}

int main()
{
  hero heroes[5]{{"刘备", 23, "男"},
                 {"关羽", 22, "男"},
                 {"张飞", 20, "男"},
                 {"赵云", 21, "男"},
                 {"貂蝉", 19, "女"}};

  int size = sizeof(heroes) / sizeof(heroes[0]);

  BubbleSort(heroes, size);
  print(heroes, size);

  return 0;
}