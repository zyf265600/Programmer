#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int lengthOfLongestSubstringKDistinct(std::string s, int k) {
    if (s.length() < k + 1) {
        return s.length();
    }

    int left = 0, right = 0;
    std::unordered_map<char, int> hashmap;
    int maxLen = k;

    while (right < s.length()) {
        if (hashmap.size() < k + 1) {
            hashmap[s[right]] = right++;
        }

        // 如果大小达到了k个
        if (hashmap.size() == k + 1) {
            // 找到最小的值并删除，更新窗口左边界
            int del_idx = *std::min_element(hashmap.begin(), hashmap.end());
            hashmap.erase(s[del_idx]);
            left = del_idx + 1;
        }

        maxLen = std::max(maxLen, right - left);
    }
    return maxLen;
}

int main() {
    std::string s = "ababbc";
    int k = 2;
    int result = lengthOfLongestSubstringKDistinct(s, k);
    std::cout << "Length of longest substring with at most " << k << " distinct characters: " << result << std::endl;
    return 0;
}