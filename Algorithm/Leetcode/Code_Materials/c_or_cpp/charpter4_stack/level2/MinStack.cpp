#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
       x_stack.pop();
       min_stack.pop();
    }
    
    int top() {
       return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main() {
   // 创建一个MinStack对象
   MinStack minStack;

   // 进行一些操作
   minStack.push(4);
   minStack.push(2);
   minStack.push(6);
   minStack.push(1);

   cout << "top: " << minStack.top() << endl; // 应该输出1
   cout << "getMin: " << minStack.getMin() << endl; // 应该输出1

   minStack.pop();
   cout << "top: " << minStack.top() << endl; // 应该输出6
   cout << "getMin: " << minStack.getMin() << endl; // 应该输出2

   return 0;
}