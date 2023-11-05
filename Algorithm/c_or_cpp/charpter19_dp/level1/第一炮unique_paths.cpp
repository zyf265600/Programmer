#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    return search(m, n);
}

int search(int m, int n) {
    if (m == 1 || n == 1) {
        return 1;
    }
    return search(m - 1, n) + search(m, n - 1);
}

int main() {
    int m = 3, n = 4;
    int result = uniquePaths(m, n);
    cout << "The number of unique paths from (0,0) to (" << m << ", " << n << ") is: " << result << endl;
    return 0;
}