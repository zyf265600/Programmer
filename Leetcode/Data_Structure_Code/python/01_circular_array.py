class CircularArray:
    def __init__(self, size=1):
        self.size = size
        self.arr = [None] * size
        self.start = 0
        self.end = 0
        self.count = 0

    def resize(self, newSize):
        new_arr = [None] * newSize
        for i in range(self.count):
            new_arr[i] = self.arr[(self.start + i) % self.size]

        self.arr = new_arr
        self.start = 0
        self.end = self.count

    def addFirst(self, val: int):
        if self.isFull():
            self.resize(self.size * 2)

        self.start = (self.start - 1 + self.size ) % self.size
        self.arr[self.start] = val
        self.count += 1

    def removeFirst(self):
        self.arr[self.start] = None
        self.start = (self.start + 1) % self.size
        self.count -= 1

    def isFull(self) -> bool:
        return self.count == self.size


def arrPrint(cArr: CircularArray):
    print("[", end="")
    for i in range(cArr.count):
        idx = (cArr.start + i) % cArr.size
        val = cArr.arr[idx]
        if val is None:
            print("_", end="")
        else:
            print(val, end="")
        if i != cArr.count - 1:
            print(", ", end="")  # 不是最后一个才加逗号
    print("]", end="")  # 保持同一行输出


if __name__ == "__main__":
    array = CircularArray(5)
    array.addFirst(3)
    array.addFirst(2)
    array.addFirst(1)
    arrPrint(array)

    print()

    array.removeFirst()
    arrPrint(array)