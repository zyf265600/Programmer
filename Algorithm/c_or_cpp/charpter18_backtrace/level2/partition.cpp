#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


bool isPalindrome(string s, int startIndex, int end) {
    for (int i = startIndex, j = end; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

void backTracking(string s, int startIndex, vector<vector<string>>& lists, stack<string>& deque) {
    if (startIndex >= s.length()) {
        lists.push_back(deque.empty() ? vector<string>() : std::vector<string>(deque.top()));
        deque.pop();
        return;
    }
    for (int i = startIndex; i < s.length(); i++) {
        if (isPalindrome(s, startIndex, i)) {
            string str = s.substr(startIndex, i - startIndex + 1);
            deque.push(str);
        } else {
            continue;
        }
        backTracking(s, i + 1, lists, deque);
        deque.pop();
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> lists;
    stack<string> deque;
    backTracking(s, 0, lists, deque);
    return lists;
}



int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);
    for (auto& list : result) {
        for (auto& str : list) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}