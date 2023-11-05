#include <iostream>
#include <stack>
#include <string>
 
//使用栈实现
using namespace std;

   bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

int main() {
    string S = "abcd";
    string t = "acbd";
    cout << isAnagram(S,t) << endl; // 输出: !dlrow, olleH
    return 0;
}