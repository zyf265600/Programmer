# coding=utf-8
class Array(object):

    def __init__(self, size=32):
        self._size = size
        self._items = [None] * size

    def __getitem__(self, index):
        return self._items[index]

    def __setitem__(self, index, value):
        self._items[index] = value

    def __len__(self):
        return self._size

    def clear(self, value=None):
        for i in range(len(self._items)):
            self._items[i] = value

    def __iter__(self):
        for item in self._items:
            yield item


if __name__ == '__main__':
    b = [0 for i in range(10)]
    # 输出结果 [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    print b

    b = [1 for i in range(10)]
    # [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    print b

    a = [10, 9, 8, 4, 5, 6, 7, 8]
    print a

    size = 10
    a = Array(size)
    a[0] = 1
    assert a[0] == 1
    assert len(a) == 10
