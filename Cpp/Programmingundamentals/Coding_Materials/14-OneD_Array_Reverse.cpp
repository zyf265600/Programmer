#include <iostream>
using namespace std;

int main()
{

    int arr[5] = {1, 3, 2, 5, 4};
    int arraySize = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = arraySize - 1;

    int temp;

    for (size_t i = 0; i < arraySize; ++i)
    {
        cout << arr[i];
    }

    cout << endl;

    for (size_t i = start; i < arraySize / 2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[end - i];
        arr[end - i] = temp;
    }

    for (size_t i = 0; i < arraySize; ++i)
    {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}