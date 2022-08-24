#include <iostream>
using namespace std;

// void bubbleSort(int *arr, int length)
// {

//     for (size_t i = 0; i < length - 1; ++i)
//     {
//         for (size_t j = 0; j < length - i - 1; ++j)
//         {
//             int temp = 0;
//             if (*arr > *(++arr))
//             {

//                 temp = *(--arr);     // fisrt
//                 *(--arr) = *(++arr); // second
//                 *(++arr) = temp;     // second
//             }
//         }

//         arr -= length - i - 1; //重置指针指第一个元素
//     }
// }

void bubbleSort(int* arr, int length) // or (int arr[], int length) or (int arr[10], int length)
{
    for (size_t i = 0; i < length - 1; ++i)
    {
        for (size_t j = 0; j < length - i - 1; ++j)
        {
            int temp = 0;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int *arr, int length)
{
    for (size_t i = 0; i < length; ++i)
    {
        cout << *arr << endl;
        arr++;
    }
}

int main()
{
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int length = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, length);
    printArray(arr, length);
}