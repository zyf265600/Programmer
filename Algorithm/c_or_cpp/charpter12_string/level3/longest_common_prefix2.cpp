#include <iostream>
#include <string>

using namespace std;

// 方法2 横向
string longestCommonPrefix(string str1, string str2) {
    int length = min(str1.length(), str2.length());
    int index = 0;
    while (index < length && str1[index] == str2[index]) {
        index++;
    }
    return str1.substr(0, index);
}


string longestCommonPrefix(string strs[], int n) {
    if (n == 0) {
        return "";
    }
    string prefix = strs[0];
    for (int i = 1; i < n; i++) {
        prefix = longestCommonPrefix(prefix, strs[i]);
        if (prefix.empty()) {
            break;
        }
    }
    return prefix;
}



int main() {
    string strs[] = {"flower", "flow", "flight"};
    int n = sizeof(strs) / sizeof(strs[0]);
    cout << longestCommonPrefix(strs, n) << endl;  // Output: "fl"
    return 0;
}