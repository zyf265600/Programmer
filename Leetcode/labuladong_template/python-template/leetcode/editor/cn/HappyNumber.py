from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def isHappy(self, n: int) -> bool:
        res = set()
        while n not in res:
            res.add(n)
            s = str(n)
            n = 0
            for c in s:
                n += int(c)**2
            # print(res)
            # print(n)
            if n == 1:
                return True
        return False
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here