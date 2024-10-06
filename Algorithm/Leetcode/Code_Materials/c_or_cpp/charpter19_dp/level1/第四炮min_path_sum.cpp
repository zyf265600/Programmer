#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> f(m, vector<int>(n, 0));
    int result = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                f[i][j] = grid[i][j];
            } else {
                int top = i - 1 >= 0 ? f[i - 1][j] + grid[i][j] : INT_MAX;
                int left = j - 1 >= 0 ? f[i][j - 1] + grid[i][j] : INT_MAX;
                f[i][j] = min(top, left);
            }
        }
    }
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (f[i][j] != INT_MAX) {
                result += f[i][j];
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << minPathSum(grid) << endl; // Output: 12
    return 0;
}