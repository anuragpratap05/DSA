#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s)
{
    int n = s.size();
    int cnt = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int g = 0; g < dp.size(); g++)
    {
        for (int i = 0, j = g; j < dp.size(); i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
                cnt++;
            }
            else if (g == 1)
            {
                if(s[i]==s[j])
                {
                    cnt++;
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (s[i] == s[j] and dp[i + 1][j - 1])
                {
                    cnt++;
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}