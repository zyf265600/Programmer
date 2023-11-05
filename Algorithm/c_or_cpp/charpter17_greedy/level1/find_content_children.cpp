#include <iostream>
#include <algorithm>
#include <vector>

int findContentChildren(std::vector<int> g, std::vector<int> s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int count = 0;
    int start = s.size() - 1;
    // 遍历孩子的胃口
    for (int index = g.size() - 1; index >= 0; index--) {
        if (start >= 0 && g[index] <= s[start]) {
            start--;
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> g = {3, 2, 1, 4, 5};
    std::vector<int> s = {3, 4, 5, 6, 7};
    int count = findContentChildren(g, s);
    std::cout << "Number of content children: " << count << std::endl;
    return 0;
}