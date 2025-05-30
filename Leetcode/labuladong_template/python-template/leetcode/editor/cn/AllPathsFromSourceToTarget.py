from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def __init__(self):
        self.res_path = []
        self.path = []

    def traverse(self, graph: List[List[int]], start:int):
        self.path.append(start)

        if start == len(graph) - 1:
            self.res_path.append(self.path.copy())
            self.path.pop()
            return

        if len(graph[start]) == 0:
            self.path.pop()
            return

        for n in graph[start]:
            self.traverse(graph, n)

        self.path.pop()


    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.traverse(graph, 0)
        return self.res_path
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here