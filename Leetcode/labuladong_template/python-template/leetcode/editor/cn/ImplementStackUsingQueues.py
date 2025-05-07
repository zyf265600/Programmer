from inspect import stack
from typing import *
from leetcode.editor.common.node import *


# leetcode submit region begin(Prohibit modification and deletion)
from queue import Queue
class MyStack:

    def __init__(self):
        self.q = Queue()
        self.top_element = 0

    def push(self, x: int) -> None:
        self.q.put(x)
        self.top_element = x

    def pop(self) -> int:
        size = self.q.qsize()
        while size > 1:
            val = self.q.get()
            self.q.put(val)
            self.top_element = val  # 更新为最后一个入队前的值
            size -= 1
        return self.q.get()  # 出栈元素

    def top(self) -> int:
        return self.top_element

    def empty(self) -> bool:
        return self.q.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# leetcode submit region end(Prohibit modification and deletion)


if __name__ == '__main__':
    solution = Solution()
    # your test code here