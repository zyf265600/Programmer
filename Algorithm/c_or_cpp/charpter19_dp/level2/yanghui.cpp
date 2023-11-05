#include <iostream>
#include <vector>

using namespace std;


vector<int> generate(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        for (int i = 1; i <= rowIndex; ++i) {
            row.push_back(0);
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
}

int main() {
 vector<int> yanghui = generate(6);
        for (int i = 0; i < yanghui.size(); i++) {
            cout << yanghui[i] << " ";
        }
        cout << endl;
}
    
