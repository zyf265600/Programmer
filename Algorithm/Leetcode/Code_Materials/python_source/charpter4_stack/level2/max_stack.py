class MaxStack:
    def __init__(self):
        self.stack = []
        self.maxStack = []

    def push(self, x):
        max_val = self.maxStack[-1] if self.maxStack else float('-inf')
        self.maxStack.append(max(max_val, x))
        self.stack.append(x)

    def pop(self):
        self.maxStack.pop()
        return self.stack.pop()

    def top(self):
        return self.stack[-1]

    def peekMax(self):
        return self.maxStack[-1]

    def popMax(self):
        max_val = self.peekMax()
        buffer = []
        while self.top() != max_val:
            buffer.append(self.pop())
        self.pop()
        while buffer:
            self.push(buffer.pop())
        return max_val
