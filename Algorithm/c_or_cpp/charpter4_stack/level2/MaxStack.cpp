#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

class MaxStack {
private:
    stack<int> data_stack;
    stack<int> max_stack;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        data_stack.push(x);
        if (max_stack.empty()) {
            max_stack.push(x);
        } else {
            max_stack.push(max(max_stack.top(), x));
        }
    }
    
    int pop() {
        int top = data_stack.top();
        data_stack.pop();
        max_stack.pop();
        return top;
    }
    
    int top() {
        return data_stack.top();
    }
    
    int peekMax() {
        return max_stack.top();
    }
    
    int popMax() {
        int max_value = max_stack.top();
        stack<int> temp;
        
        while (data_stack.top() != max_value) {
            temp.push(data_stack.top());
            data_stack.pop();
            max_stack.pop();
        }
        
        data_stack.pop();
        max_stack.pop();
        
        while (!temp.empty()) {
            int x = temp.top();
            temp.pop();
            push(x);
        }
        
        return max_value;
    }
};

int main() {
MaxStack maxStack;

    maxStack.push(5); // 栈: [5]，最大值: 5
    maxStack.push(1); // 栈: [5, 1]，最大值: 5
    maxStack.push(4); // 栈: [5, 1, 4]，最大值: 5
    maxStack.push(9); // 栈: [5, 1, 4, 9]，最大值: 9


    cout << "栈顶元素: " << maxStack.top() << endl; // 输出: 9
    cout << "当前最大值: " << maxStack.peekMax() << endl; // 输出: 9

    cout << "移除栈顶元素: " << maxStack.pop() << endl; // 输出: 9
    cout << "当前最大值: " << maxStack.peekMax() << endl; // 输出: 5

    cout << "移除最大值: " << maxStack.popMax() << endl; // 输出: 5
    cout << "栈顶元素: " << maxStack.top() << endl; // 输出: 4
    cout << "当前最大值: " << maxStack.peekMax() << endl; // 输

}