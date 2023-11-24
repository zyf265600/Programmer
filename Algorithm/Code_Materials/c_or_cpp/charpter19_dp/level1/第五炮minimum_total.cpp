#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& tri) {
    int n = tri.size();
    int ans = INT_MAX;
    int[][] f = new int[n][n];
    f[0][0] = tri[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            int val = tri[i][j];
            f[i][j] = INT_MAX;
            if (j != 0) {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + val);
            }
            if (j != i) {
                f[i][j] = min(f[i][j], f[i - 1][j] + val);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans = min(ans, f[n - 1][i]);
    }
    return ans;
}

int main() {
    vector<vector<int>> tri = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minimumTotal(tri) << endl; // Output: 12
    return 0;
}