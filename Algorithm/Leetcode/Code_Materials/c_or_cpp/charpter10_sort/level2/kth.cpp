#include <vector>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &nums, int l, int r)
{
    // 子数组长度为 1 时终止递归
    if (l >= r)
        return;
    // 哨兵划分操作（以 nums[l] 作为基准数）
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && nums[j] >= nums[l])
            j--;
        while (i < j && nums[i] <= nums[l])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[l]);
    // 递归左（右）子数组执行哨兵划分
    quickSort(nums, l, i - 1);
    quickSort(nums, i + 1, r);
}
int findKthLargest(vector<int> &nums, int k)
{
    quickSort(nums, 0, nums.size() - 1);
    return nums[nums.size() - k];
}

int main()
{
 
    vector<int> nums; // 定义一个空的 vector<int> 类型的变量
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(8);
    vector<int> &array = nums; // 将 nums 赋值给另一个变量 other_nums，使得 other_nums 可以修改 nums 的内容

    cout << findKthLargest(array, 2) << endl;

    return 0;
}