#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();
    int write = 0, left = 0;
    for (int read = 0; read < n; read++)
    {
        if (read == n - 1 || chars[read] != chars[read + 1])
        {
            chars[write++] = chars[read];
            int num = read - left + 1;
            if (num > 1)
            {
                int anchor = write;
                while (num > 0)
                {
                    chars[write++] = num % 10 + '0';
                    num /= 10;
                }
                reverse(&chars[anchor], &chars[write]);
            }
            left = read + 1;
        }
    }
    return write;
}

int main()
{
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    int result = compress(chars);
    return 0;
}