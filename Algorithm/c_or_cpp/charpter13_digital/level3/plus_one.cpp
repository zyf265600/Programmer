#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] != 9) {
            ++digits[i];
            for (int j = i + 1; j < n; ++j) {
                digits[j] = 0;
            }
            return digits;
        }
    }

    // digits 中所有的元素均为 9
    vector<int> ans(n + 1);
    ans[0] = 1;
    return ans;
}

int main() {
    vector<int> digits ;
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(9);
    vector<int> result = plusOne(digits);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}