#include <iostream>
#include<vector>
using namespace std;
 
 int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size(), n = s.size();
        int count = 0;
        for (int i = 0, j = 0; i < m && j < n; i++, j++) {
            while (j < n && g[i] > s[j]) {
                j++;
            }
            if (j < n) {
                count++;
            }
        }
        return count;
    }
 

int main() {
    std::vector<int> g = {1,2,3};
    std::vector<int> s = {1,1};
    int count = findContentChildren(g, s);
    std::cout << "Number of content children: " << count << std::endl;
    return 0;
     
}