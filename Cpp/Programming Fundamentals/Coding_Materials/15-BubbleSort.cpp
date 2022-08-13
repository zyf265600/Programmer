#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};

    int size = sizeof(arr) / sizeof(arr[0]);
    int temp;

    //排序前
    for (size_t i = 0; i < size; ++i)
    {
        cout << arr[i];
    }
    cout << endl;

    for (size_t i = 0; i < size - 1; ++i)
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    //排序后
    for (size_t i = 0; i < size; ++i)
    {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}