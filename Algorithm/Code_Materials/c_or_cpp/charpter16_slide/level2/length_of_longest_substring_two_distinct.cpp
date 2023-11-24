#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


int lengthOfLongestSubstringTwoDistinct(std::string s) {
    int n = s.length();
    if (n < 3) {
        return n;
    }
    int left = 0, right = 0;
    std::unordered_map<char, int> hashmap;
    int max_len = 2;
    while (right < n) {
        if (hashmap.size() < 3) {
            hashmap[s[right]] = right;
            right++;
        } else {
            int del_idx = *std::min_element(hashmap.begin(), hashmap.end());
            hashmap.erase(del_idx);
            left = del_idx + 1;
        }
        max_len = std::max(max_len, right - left + 1);
    }
    return max_len;
}

int main() {
    std::string s = "abcabbb";
    int result = lengthOfLongestSubstringTwoDistinct(s);
    std::cout << "Length of longest substring with at most two distinct characters: " << result << std::endl;
    return 0;
}