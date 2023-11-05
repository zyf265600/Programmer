
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto& bill: bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    } 


int main() {
    std::vector<int> g = {5,5,5,10,20};
 
    int count = lemonadeChange(g);
    std::cout << " " << count << std::endl;
    return 0;
     
}