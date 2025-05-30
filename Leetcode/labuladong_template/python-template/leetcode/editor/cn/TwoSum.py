from collections import defaultdict
from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        bank = {}
        for i, n in enumerate(nums):
            rest = target - n
            if rest in bank:
                return [bank.get(rest), i]
            else:
                bank[n] = i
                # print(bank)
        return []

        # for i, n in enumerate(nums):
        #     rest = target - n
        #
        #     if rest in nums[i+1:]:
        #         return [i, nums[i+1:].index(rest) + i + 1]
        #
        #
        # return []


        # for idx, n in enumerate(nums):
        #     diff = target - n
        #
        #     for i, nn in enumerate(nums[idx+1:]):
        #         if diff == nn:
        #             return [idx, idx+1+i]
        #
        # return []
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here

    # print(solution.twoSum([1,2],1))