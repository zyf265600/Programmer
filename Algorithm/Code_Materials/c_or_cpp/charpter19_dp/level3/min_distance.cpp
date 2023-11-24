#include <iostream>
#include <vector>
using namespace std;

int minDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; j++) {
        f[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        f[i][0] = i;
        for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i - 1][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i][j - 1] + 1);
            if (s1[i - 1] == s2[j - 1]) {
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
        }
    }
    return f[m][n];
}

int main() {
    string s1 = "abcd";
    string s2 = "bcdf";
    cout << minDistance(s1, s2) << endl; // Output: 3
    return 0;
}