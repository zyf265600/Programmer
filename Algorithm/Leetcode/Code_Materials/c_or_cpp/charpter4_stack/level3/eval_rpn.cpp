#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
using namespace std;

class EvalRPN {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for (string token : tokens) {
            if (isOperator(token)) {
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();

                int result = calculate(num1, num2, token);
                numStack.push(result);
            } else {
                int num = stringToInt(token);
                numStack.push(num);
            }
        }
        return numStack.top();
    }

private:
    bool isOperator(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int calculate(int num1, int num2, string op) {
        if (op == "+") {
            return num1 + num2;
        } else if (op == "-") {
            return num1 - num2;
        } else if (op == "*") {
            return num1 * num2;
        } else if (op == "/") {
            return num1 / num2;
        } else {
            return 0; // 这里可以根据需求来返回其他处理结果
        }
    }

    int stringToInt(string token) {
        int num;
        stringstream ss(token);
        ss >> num;
        return num;
    }
};

int main() {
    EvalRPN evalRPN;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = evalRPN.evalRPN(tokens);
    cout << "Result: " << result << endl;
    return 0;
}