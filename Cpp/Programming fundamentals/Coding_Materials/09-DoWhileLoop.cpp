#include <iostream>
using namespace std;

int main()
{

    int num = 100;
    int single;
    int ten;
    int hundred;

    do
    {
        single = num % 10;
        ten = (num % 100 - single) / 10;
        hundred = num / 100;
        if (single *single *single + ten *ten *ten + hundred *hundred *hundred == num)
        {
            cout << num << endl;
        }

        ++num;

    } while (num < 1000);

    return 0;
}