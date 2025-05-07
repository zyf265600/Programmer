from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        res = False

        target, window = {}, {}

        left, right, valid  = 0, 0, 0

        # in the target string, how many char include
        for c in s1:
            target[c] = target.get(c, 0)  + 1

        while right < len(s2):
            c = s2[right]
            right+=1

            window[c] = window.get(c, 0) + 1

            if c in target:
                if window[c] == target[c]:
                    valid += 1

            if right - left == len(s1):
                if valid == len(target):
                    return True

                d = s2[left]

                if d in target:
                    if window[d] == target[d]:
                        valid -= 1

                window[d] -= 1

                left+=1

        return res
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here