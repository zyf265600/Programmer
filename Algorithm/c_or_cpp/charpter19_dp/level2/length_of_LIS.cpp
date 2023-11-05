#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    int f[n];
    int i, j, res = 0;
    for (j = 0; j < n; j++) {
        f[j] = 1;
        for (i = 0; i < j; i++) {
            if (A[i] < A[j] && f[i] + 1 > f[j]) {
                f[j] = f[i] + 1;
            }
        }
        res = max(res, f[j]);
    }
    return res + 1;
}

int main() {
    vector<int> A = {1, 3, 5, 7, 9};
    cout << lengthOfLIS(A) << endl;   
    return 0;
}