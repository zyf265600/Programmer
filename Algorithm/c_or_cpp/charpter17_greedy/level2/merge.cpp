#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
 

int main() {
    int[][] intervals = {{1, 3}, {2, 5}, {4, 6}};
    int[][] merged = merge(intervals);
    for (int i = 0; i < merged.length; i++) {
        for (int j = 0; j < merged[i].length; j++) {
            cout << merged[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

