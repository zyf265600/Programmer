from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0

        left, right = 0, 0

        chars = {}

        while right < len(s):
            c = s[right]
            right += 1

            chars[c] = chars.get(c, 0) + 1

            while chars[c] > 1:
                d = s[left]
                left += 1
                chars[d] -= 1
                if chars[d] == 0:
                    del chars[d]

            res = max(res, right - left)

        return res
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here