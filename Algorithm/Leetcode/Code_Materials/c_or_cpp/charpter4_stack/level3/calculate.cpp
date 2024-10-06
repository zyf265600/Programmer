#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Calculate {
public:
    int calculate(string s) {
        stack<int> numStack;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            // 当遇到运算符或者到达字符串结尾时计算结果
            if (!isdigit(c) && c != ' ' || i == s.length() - 1) {
                if (sign == '+') {
                    numStack.push(num);
                } else if (sign == '-') {
                    numStack.push(-num);
                } else if (sign == '*') {
                    int prevNum = numStack.top();
                    numStack.pop();
                    numStack.push(prevNum * num);
                } else if (sign == '/') {
                    int prevNum = numStack.top();
                    numStack.pop();
                    numStack.push(prevNum / num);
                }
                sign = c;
                num = 0;
            }
        }
        int result = 0;
        while (!numStack.empty()) {
            result += numStack.top();
            numStack.pop();
        }
        return result;
    }
};

int main() {
    Calculate calculate;

    // 测试用例1
    string str1 = "3+2*2";
    int result1 = calculate.calculate(str1);
    cout << "Result 1: " << result1 << endl;

    // 测试用例2
    string str2 = " 3/2 ";
    int result2 = calculate.calculate(str2);
    cout << "Result 2: " << result2 << endl;

    // 测试用例3
    string str3 = " 3+5 / 2 ";
    int result3 = calculate.calculate(str3);
    cout << "Result 3: " << result3 << endl;

    // 更多测试用例...

    return 0;
}