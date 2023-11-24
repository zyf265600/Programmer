# coding=utf-8
import collections


class MyQueue:

    def __init__(self):
        self.stack_in = []
        self.stack_out = []

    def push(self, x):
        self.stack_in.append(x)

    def pop(self):
        if self.empty():
            return None

        if self.stack_out:
            return self.stack_out.pop()
        else:
            for i in range(len(self.stack_in)):
                self.stack_out.append(self.stack_in.pop())
            return self.stack_out.pop()

    def peek(self):
        ans = self.pop()
        self.stack_out.append(ans)
        return ans

    def empty(self):
        return not (self.stack_in or self.stack_out)


if __name__ == '__main__':
    que = MyQueue()
    que.push(1)
    que.push(2)
    que.push(3)
    print(que.pop())  # 输出1
    print(que.empty())  # 输出False
