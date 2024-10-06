#include <iostream>
#include<vector>
using namespace std;
bool checkInclusion(string s1, string s2) {
    int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; ++i) {
            ++cnt1[s1[i] - 'a'];
            ++cnt2[s2[i] - 'a'];
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = n; i < m; ++i) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;

 
}

int main() {
    std::string s1 = "abcd";
    std::string s2 = "abpc";
    if (checkInclusion(s1, s2)) {
        std::cout << "s1 is included in s2" << std::endl;
    } else {
        std::cout << "s1 is not included in s2" << std::endl;
    }
    return 0;
}