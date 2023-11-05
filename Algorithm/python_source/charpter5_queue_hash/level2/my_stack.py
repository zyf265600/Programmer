# coding=utf-8
import collections


class MyStack:

    def __init__(self):
        self.queue1 = collections.deque()
        self.queue2 = collections.deque()

    def push(self, x):
        self.queue2.append(x)
        while self.queue1:
            self.queue2.append(self.queue1.popleft())
        self.queue1, self.queue2 = self.queue2, self.queue1

    def pop(self):
        return self.queue1.popleft()

    def top(self):
        return self.queue1[0]

    def empty(self):
        return not self.queue1


if __name__ == '__main__':
    stack = MyStack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print(stack.pop())  # 输出3
    print(stack.top())  # 输出2
    print(stack.empty())  # 输出False
