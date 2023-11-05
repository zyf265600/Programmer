# coding=utf-8

# 方法1：使用栈结构
def reverseOnlyLetters1(S) :
    letters = []
    for c in S:
        if c.isalpha():
            letters.append(c)

    ans = ""
    for c in S:
        if c.isalpha():
            ans += letters.pop()
        else:
            ans += c

    return ans

# 双指针
def reverseOnlyLetters(S):
    if not S:
        return S
    ans = []
    j = len(S) - 1
    for i in range(len(S)):
        if S[i].isalpha():
            while not S[j].isalpha():
                j -= 1
            ans.append(S[j])
            j -= 1
        else:
            ans.append(S[i])
    return ''.join(ans)

S = "Hello World"
print("Original String:", S)
reversed_str = reverseOnlyLetters(S)
print("Reversed String:", reversed_str)