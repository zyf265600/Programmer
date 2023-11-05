class MinStack:
    def __init__(self):
        self.xStack = []
        self.minStack = []
        self.minStack.append(float('inf'))

    def push(self, x):
        self.xStack.append(x)
        self.minStack.append(min(self.minStack[-1], x))

    def pop(self):
        self.xStack.pop()
        self.minStack.pop()

    def top(self):
        return self.xStack[-1]

    def getMin(self):
        return self.minStack[-1]