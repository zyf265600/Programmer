from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        sum12 = Counter(x + y for x in nums1 for y in nums2)
        # print(sum12)
        sum34 = Counter(x + y for x in nums3 for y in nums4)

        return sum(sum12[-x] * sum34[x] for x in sum34)
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here