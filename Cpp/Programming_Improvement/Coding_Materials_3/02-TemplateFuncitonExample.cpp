#include <iostream>
using namespace std;

template <class T>
void Sort(T arr[], int size)
{
    for (size_t i = 0; i < size - 1; ++i)
    {
        int min = i;
        for (size_t j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        T temp;
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

template <class T>
void printArray(T arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int intArr[] = {7, 5, 8, 1, 3, 9, 2, 4, 6};
    char charArr[]{"adcbfeg"};
    Sort(intArr, 9);
    Sort<char>(charArr, 7);

    printArray(intArr, 9);
    printArray(charArr, 7);

    return 0;
}
