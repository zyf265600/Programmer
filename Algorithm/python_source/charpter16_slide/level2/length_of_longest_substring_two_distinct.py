# coding=utf-8
from collections import defaultdict

class LengthOfLongestSubstringTwoDistinct:
    def lengthOfLongestSubstringTwoDistinct(self, s):
        n = len(s)
        if n < 3:
            return n
        left, right = 0, 0
        hashmap = defaultdict()
        max_len = 2
        while right < n:
            if len(hashmap) < 3:
                hashmap[s[right]] = right
                right += 1
            if len(hashmap) == 3:
                del_idx = min(hashmap.values())
                del hashmap[s[del_idx]]
                left = del_idx + 1
            max_len = max(max_len, right - left)
        return max_len

if __name__ == '__main__':
    s = "eceba"
    lengthOfLongestSubstringTwoDistinct = LengthOfLongestSubstringTwoDistinct()
    print lengthOfLongestSubstringTwoDistinct.lengthOfLongestSubstringTwoDistinct(s)
