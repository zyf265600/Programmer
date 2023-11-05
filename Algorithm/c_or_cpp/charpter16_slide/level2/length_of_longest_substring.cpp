#include <iostream>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    if (s.empty()) return 0;
    std::unordered_map<char, int> map;
    int max = 0;
    int left = 0;
    for (int right = 0; right < s.length(); right++) {
        if (map.count(s[right]) > 0) {
            left = std::max(left, map[s[right]] + 1);
        }
        map[s[right]] = right;
        max = std::max(max, right - left + 1);
    }
    return max;
}

int main() {
    std::string s = "abcabc";
    int result = lengthOfLongestSubstring(s);
    std::cout << "Length of longest substring: " << result << std::endl;
    return 0;
}