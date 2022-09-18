#include <iostream>

using namespace std;

void Merge(int a[], int s, int mid, int e, int tmp[]); //归并
void Merge_Sort(int a[], int s, int e, int tmp[]);     //有序

int main()
{
    int a[1000], tmp[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Merge_Sort(a, 0, n - 1, tmp); //对数组进行排序
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

void Merge_Sort(int a[], int s, int e, int tmp[])
{
    if (s < e)
    {
        int m = (s + e) / 2;
        Merge_Sort(a, s, m, tmp);     //左边有序
        Merge_Sort(a, m + 1, e, tmp); //右边有序
        Merge(a, s, m, e, tmp);       //归并
    }
}

void Merge(int a[], int s, int mid, int e, int tmp[])
{
    int p1, p2, p = 0;
    p1 = s, p2 = mid + 1;
    //判断大小，得到排列顺序
    while (p1 <= mid && p2 <= e)
    {
        if (a[p1] < a[p2])
        {
            tmp[p++] = a[p1++];
        }
        else
        {
            tmp[p++] = a[p2++];
        }
    }
    //剩余数据自动放到末尾
    while (p1 <= mid)
    {
        tmp[p++] = a[p1++];
    }
    while (p2 <= e)
    {
        tmp[p++] = a[p2++];
    }
    //将tmp中排好序的数组拷贝到a中
    for (int i = 0; i < e - s + 1; ++i)
    {
        a[s + i] = tmp[i];
    }
}