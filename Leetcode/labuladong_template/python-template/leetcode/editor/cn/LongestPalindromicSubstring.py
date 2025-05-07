from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""

        for i in range(len(s)):
            res1 = self.detectPalindrome(s, i, i)
            res2 = self.detectPalindrome(s, i, i+1)

            res = res1 if len(res) < len(res1) else res
            res = res2 if len(res) < len(res2) else res

        return res


    def detectPalindrome(self, s : str, left: int, right: int) -> str:
        res = ""

        while left >= 0 and right < len(s) and s[left] == s[right]:
            res = s[left] + res + s[right] if left != right else s[left]
            left -= 1
            right += 1

        return res

        # return s[l + 1:r]
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here