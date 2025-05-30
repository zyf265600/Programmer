from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        if nums is None:
            return -1

        res = -1

        nums_sum = sum(nums)
        # print(nums_sum)
        window = 0

        left = 0
        right = 0

        while right < len(nums):
            window += nums[right]
            right += 1

            # print(left)
            # print(right)

            while left < right and window > nums_sum - x:
                window -= nums[left]
                left += 1

            if window == nums_sum - x:
                res = max(res, right - left)

        return -1 if res == - 1 else len(nums) - res
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here