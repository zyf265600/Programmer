#include <iostream>
using namespace std;

int main()
{

    int count = 10;

    for (size_t i = 1; i < count; ++i)
    {
        for (size_t j = 1; j < i + 1; ++j)
        {
            cout << j << "*" << i << "=" << i * j << "\t";
        }
        cout << endl;
    }
}