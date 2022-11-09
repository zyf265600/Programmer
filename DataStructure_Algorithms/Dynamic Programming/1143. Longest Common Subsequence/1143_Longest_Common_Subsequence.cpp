#include <iostream>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{

    int one = 0;
    while (text1[one] != '\0')
    {
        one += 1;
    }
    int sizeofone = one;

    // cout << sizeofone << endl;

    int two = 0;
    while (text2[two] != '\0')
    {
        two += 1;
    }
    int sizeoftwo = two;

    // cout << sizeoftwo << endl;

    int dp[sizeofone + 1][sizeoftwo + 1];

    for (size_t i = 0; i < sizeofone + 1; i++)
    {
        for (size_t j = 0; j < sizeoftwo + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // initialize base case, either string is null
    // when text1 is null
    for (int i = 0; i <= sizeoftwo; ++i)
    {
        dp[0][i] = 0;
    }
    // when text2 is null
    for (int j = 0; j <= sizeofone; ++j)
    {
        dp[j][0] = 0;
    }


    for (size_t i = 0; i < sizeofone + 1; i++)
    {
        for (size_t j = 0; j < sizeoftwo + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;

    for (int i = 1; i <= sizeofone; ++i)
    {

        for (int j = 1; j <= sizeoftwo; ++j)
        {

            if (text1[i - 1] != text2[j - 1])
            {
                dp[i][j] = dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
                
                for (size_t i = 0; i < sizeofone + 1; i++)
                {
                    for (size_t j = 0; j < sizeoftwo + 1; j++)
                    {
                        cout << dp[i][j] << " ";
                    }
                    cout << endl;
                }

                cout << endl;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    return dp[sizeofone][sizeoftwo];
}

int main()
{

    cout << longestCommonSubsequence("abc", "def")
         << endl;
    return 0;
}