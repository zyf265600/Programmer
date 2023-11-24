#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1, res = 0;
    while (i < j) {
        res = std::max(res, std::max(height[i], height[j]) * (j - i));
        if (height[i] > height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return res;
}

int main() {
    int height[] = {3, 2, 1, 4, 5, 6};
    int heightSize = sizeof(height) / sizeof(height[0]);
    std::cout << maxArea(height, heightSize) << std::endl; // 输出6，即最大子数组的长度为3，高度为6的子数组
    return 0;
}