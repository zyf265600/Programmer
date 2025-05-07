from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res = []

        target, window = {}, {}
        left, right, valid = 0, 0 ,0

        for c in p:
            target[c] = target.get(c, 0) + 1

        while right < len(s):
            c = s[right]
            right += 1

            window[c] = window.get(c, 0) + 1

            if c in target and window[c] == target[c]:
                valid += 1

            if right - left == len(p):
                if valid == len(target):
                     res.append(left)

                d = s[left]

                if d in target and window[d] == target[d]:
                    valid -= 1

                window[d] -= 1

                left += 1


        return res
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here