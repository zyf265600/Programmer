#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& A) {
    int result = 0;
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    int* f = new int[n];
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        if (i > 0 && A[i] > A[i - 1]) {
            f[i] = f[i - 1] + 1;
        }
        if (f[i] > result) {
            result = f[i];
        }
    }
    delete[] f;
    return result + 1;
}

int main() {
    vector<int> A = {1, 3, 5, 7, 9};
    cout << findLengthOfLCIS(A) << endl;  // Output: 4
    return 0;
}