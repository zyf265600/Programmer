#include <iostream>
#include <string>

using namespace std; 

 bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
           if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

int main() {
    char s[] = "abba";
    cout<<isPalindrome(s)<<endl;
   
    return 0;
}    