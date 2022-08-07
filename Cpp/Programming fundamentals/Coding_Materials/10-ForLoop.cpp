#include <iostream>
using namespace std;

int main()
{

    int num = 100;
    int single;
    int ten;
    int hundred;

    for (size_t i = 1; i <= num; i++)
    {
        single = i % 10;
        ten = (i % 100 - single) / 10;
        hundred = i / 100;

        if ((single == 7) || (ten == 7) || (i % 7 == 0))
        {
            cout << "敲桌子" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
}