# coding=utf-8
class EvalRPN:
    def evalRPN(self, tokens):
        stack = []

        for token in tokens:
            if len(token) == 1 and not token.isdigit():
                # 运算符，从栈中取出两个数进行运算！
                b = stack.pop()
                a = stack.pop()

                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                elif token == '/':
                    stack.append(int(a / b))
            else:
                # 整数直接入栈！
                stack.append(int(token))

        return stack.pop()

if __name__ == '__main__':
    tokens = ["2", "1", "+", "3", "*"]
    solution = EvalRPN()
    result = solution.evalRPN(tokens)
    print("The result is:", result)