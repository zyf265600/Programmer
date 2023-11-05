#include <iostream>
#include <string>

using namespace std;

// 方法1，纵向
string longestCommonPrefix(string strs[], int n) {
    if (n == 0) {
        return "";
    }
    int length = strs[0].length();
    for (int i = 0; i < length; i++) {
        char c = strs[0][i];
        for (int j = 1; j < n; j++) {
            if (i == strs[j].length() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}
 


int main() {
    string strs[] = {"flower", "flow", "flight"};
    int n = sizeof(strs) / sizeof(strs[0]);
    cout << longestCommonPrefix(strs, n) << endl;  // Output: "fl"
    return 0;
}