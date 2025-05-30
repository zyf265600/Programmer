from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        temp = Counter(words[0])

        for w in words[1:]:
            temp = temp & Counter(w)

        res = []

        for c in temp:
            while temp[c] != 0:
                temp[c] -= 1
                res.append(c)

        # print(temp)

        return res

# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here