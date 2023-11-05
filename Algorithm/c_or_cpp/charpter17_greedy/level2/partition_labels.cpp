#include <iostream>
#include <vector>
using namespace std;

 vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
 
int main() {
    string S = "abacb";
    vector<int> result = partitionLabels(S);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl; // 输出：2 1 0 1 2 2 2 3 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
    return 0;
}