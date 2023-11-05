# coding=utf-8
from collections import deque
def reverseString(s):
    if s is None or len(s) == 0:
        return s

    left, right = 0, len(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1

    return s

s = list("Hello World")
reverseString(s)
print(''.join(s))  # 输出：dlroW olleH