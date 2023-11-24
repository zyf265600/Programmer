#include <stdio.h>

int findByElement(int arr[], int size, int key);

int addByElementSequence(int arr[], int size, int element);

void testInitArray()
{
    // 初始化
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    // 测试查找
    int index = findByElement(arr, size, key);
    if (index == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", index);
    }
}

void testInitAdd()
{
    // 初始化
    int arr[6] = {1, 2, 3, 4, 5};
    
    int key = 3;

    addByElementSequence(arr, 5, 7);

    for (size_t i = 0; i < 6; i++)
    {
         printf("array[%d] is  %d\n", i,arr[i]);
    }
    
   
}

int main()
{

    // testInitArray();
    testInitAdd();


    return 0;
}

// 查找元素
int findByElement(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int addByElementSequence(int arr[], int len,int size, int element)
{
    if (size >len))
    {
        return -1;
    }

    int index = size;
    for (int i = 0; i < size; i++)
    {
        if (element < arr[i])
        {
            index = i;
            break;
        }
    }
    for (int j = size; j > index; j--)
    {
        arr[j] = arr[j - 1];
    }
    return size + 1;
}
