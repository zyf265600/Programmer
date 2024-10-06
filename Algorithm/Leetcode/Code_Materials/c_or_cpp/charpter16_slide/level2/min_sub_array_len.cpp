#include <iostream>
#include <vector>
#include <algorithm>

int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0, right = 0, sum = 0, min = INT_MAX;
    while (right < numsSize) {
        sum += nums[right++];
        while (sum >= target) {
            min = std::min(min, right - left);
            sum -= nums[left++];
        }
    }
    return min == INT_MAX ? 0 : min;
}

int main() {
    int target = 10;
    int nums[] = {1, 2, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = minSubArrayLen(target, nums, numsSize);
    std::cout << "Length of longest substring with at most " << target << " distinct characters: " << result << std::endl;
    return 0;
}