# coding=utf-8

def addStrings( num1, num2) :
        res = ""
        i, j, carry = len(num1) - 1, len(num2) - 1, 0

        while i >= 0 or j >= 0:
            n1 = int(num1[i]) if i >= 0 else 0
            n2 = int(num2[j]) if j >= 0 else 0

            tmp = n1 + n2 + carry
            carry = tmp // 10

            res = str(tmp % 10) + res
            i -= 1
            j -= 1

        return "1" + res if carry else res


if __name__ == '__main__':
    num1 = "123"
    num2 = "456"
    result = addStrings(num1, num2)
    print(result) # 输出：579