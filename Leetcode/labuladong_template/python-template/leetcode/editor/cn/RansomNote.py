from collections import defaultdict
from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False

        res = True

        bank = Counter(magazine)
        # print(bank)
        for r in ransomNote:
            if r in bank and bank[r] != 0:
                bank[r] -= 1
            else:
                return False

        return res

        # if len(ransomNote) > len(magazine):
        #     return False
        #
        # resource = defaultdict(int)
        # for m in magazine:
        #     resource[m] += 1
        #
        # for r in ransomNote:
        #     if resource[r] == 0:
        #         return False
        #     resource[r] -= 1
        #
        # return True

# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here