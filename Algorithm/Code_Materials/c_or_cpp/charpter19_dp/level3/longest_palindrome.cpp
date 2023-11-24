#include <iostream>
#include <vector>
using namespace std;

int longestPalindrome(string s) {
    char arr[s.length()];
    for (int i = 0; i < s.length(); i++) {
        arr[i] = s[i];
    }
    int n = s.length();
    if (n == 0) {
        return 0;
    }

    int f[n][n];
    int i, j = 0;
    for (i = 0; i < n; i++) {
        f[i][j] = 1;
    }

    for (i = 0; i < n - 1; i++) {
        f[i][i + 1] = (arr[i] == arr[i + 1]) ? 2 : 1;
    }
    for (int len = 3; len <= n; len++) {
        for (i = 0; i <= n - len; i++) {
            j = i + len - 1;
            f[i][j] = max(f[i][j - 1], f[i + 1][j]);
            if (arr[i] == arr[j]) {
                f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
            }
        }
    }
    return f[0][n - 1];
}

int main() {
    string s = "abccba";
    cout << longestPalindrome(s) << endl; // Output: 4
    return 0;
}