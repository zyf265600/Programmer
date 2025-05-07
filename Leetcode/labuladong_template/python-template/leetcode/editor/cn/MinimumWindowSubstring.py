from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    # def contains_all_bruteforce(self, s: str, t: str, i: int, j: int) -> bool:
    #     target = {}
    #     for c in t:
    #         if c not in target:
    #             target[c] = 0
    #         target[c] += 1
    #
    #     input = {}
    #     for index in range(i, j):
    #         if s[index] not in input:
    #             input[s[index]] = 0
    #         input[s[index]] += 1
    #
    #
    #     for c in target:
    #         if c not in input or input[c] < target[c]:
    #             return False
    #
    #     return True
    #
    #
    # def minWindow(self, s: str, t: str) -> str:
    #     res = ""
    #     for i in range(len(s)):
    #         for j in range(i + 1, len(s) + 1):
    #             if self.contains_all_bruteforce(s, t, i, j):
    #                 if res == "" or (j - i) < len(res):
    #                     res = s[i:j]
    #
    #     return res

    def minWindow(self, s: str, t: str) -> str:
        target, window = {}, {}
        res = ""

        for c in t:
            target[c] = target.get(c, 0) + 1

        left = 0
        right = 0
        valid = 0

        while right < len(s):
            c = s[right]
            right += 1

            if c in target:
                window[c] = window.get(c, 0) + 1
                if window[c] == target[c]:
                    valid += 1

            while valid == len(target):
                if res == "" or (right - left) < len(res):
                    res = s[left:right]

                remove = s[left]
                left += 1

                if remove in target:
                    if window[remove] == target[remove]:
                        valid -= 1
                    window[remove] -= 1

        return res




# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here
    solution.minWindow("ADOBECODEBANC", "ABC")