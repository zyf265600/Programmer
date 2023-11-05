#include <stdio.h>

void quickSort(int *array, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int left = start, right = end;
    int pivot = array[(start + end) / 2];

    while (left <= right)
    {
        while (left <= right && array[left] < pivot)
        {
            left++;
        }
        while (left <= right && array[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    // 先处理元素再分别递归处理两侧分支，与二叉树的前序遍历非常像
    quickSort(array, start, right);
    quickSort(array, left, end);
}

int main()
{
    int array[] = {5, 2, 9, 3, 7, 6, 1, 8, 4};
    int n = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}