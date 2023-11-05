#include <iostream>
#include <stack>
#include <string>
//使用栈实现
using namespace std;

string reverseOnlyLetters(string S) {
    stack<char> letters;
    for (char c : S) {
        if (isalpha(c)) {
            letters.push(c);
        }
    }
    string ans = "";
    for (char c : S) {
        if (isalpha(c)) {
            ans += letters.top();
            letters.pop();
        } else {
            ans += c;
        }
    }
    return ans;
}

int main() {
    string S = "Hello, world!";
    cout << reverseOnlyLetters(S) << endl; // 输出: !dlrow, olleH
    return 0;
}