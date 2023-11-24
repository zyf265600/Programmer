#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
//使用栈实现
using namespace std;

  int firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (char ch: s) {
            ++frequency[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequency[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }

int main() {
    string S = "Helloworld!";
    cout << firstUniqChar(S) << endl; // 输出: !dlrow, olleH
    return 0;
}