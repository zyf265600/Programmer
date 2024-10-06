# coding=utf-8
def reverseStr(s, k)
    if s is None or len(s) == 0:
        return s
    arr = list(s)
    n = len(arr)
    for i in range(0, n, 2 * k):
        arr[i:i+k] = reversed(arr[i:i+k])
    return "".join(arr)

s = "Hello World"
k = 3
print("Original String:", s)
reversed_str = reverseStr(s, k)
print("Reversed String:", reversed_str)