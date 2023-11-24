#include <iostream>
#include <vector>

using namespace std;

bool check(string s, int i) {
    if (s[i - 2] == '0') {
        return false;
    }
    int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
    if (num > 26) {
        return false;
    }
    return true;
}

int numDecodings(string s) {
    int n = s.length();
    vector<int> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] != '0') {
            f[i] += f[i - 1];
        }
        if (i > 1 && check(s, i)) {
            f[i] += f[i - 2];
        }
    }
    return f[n];
}



int main() {
    string s = "132"; // Example input string
    int result = numDecodings(s);
    cout << "Number of ways to decode the string: " << result << endl;
    return 0;
}