#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s1, string s2) {
    char s1[] = s1.c_str();
    char s2[] = s2.c_str();
    int m = s1.length();
    int n = s2.length();
    bool (*f)[n + 1] = new bool[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        f[i][0] = (i == 0);
        for (int j = 1; j <= n; j++) {
            f[i][j] = false;
            if (s2[j - 1] != '*') {
                if (i > 0 && (s2[j - 1] == '.' || s2[j - 1] == s1[i - 1])) {
                    f[i][j] |= f[i - 1][j - 1];
                }
            } else {
                if (j - 2 >= 0) {
                    f[i][j] |= f[i][j - 2];
                }
                if (i > 0 && j - 2 >= 0 && (s2[j - 2] == '.' || s2[j - 2] == s1[i - 1])) {
                    f[i][j] |= f[i - 1][j];
                }
            }
        }
    }
    return f[m][n];
}

int main() {
    string s1 = "ab";
    string s2 = "a.*b";
    cout << isMatch(s1, s2) << endl; // Output: true
    return 0;
}