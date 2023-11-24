#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& A) {
    if (A.empty() || A.size() == 0) {
        return false;
    }
    int n = A.size();
    bool f[n];
    f[0] = true;
    for (int j = 1; j < n; j++) {
        f[j] = false;
        for (int i = 0; i < j; i++) {
            if (f[i] && (i + A[i] >= j)) {
                f[j] = true;
            }
        }
    }
    return f[n - 1];
}

int main() {
    vector<int> A = {2, 3, 1, 1, 4};
    bool result = canJump(A);
    cout << "Can the player jump to the end? " << (result ? "Yes" : "No") << endl;
    return 0;
}