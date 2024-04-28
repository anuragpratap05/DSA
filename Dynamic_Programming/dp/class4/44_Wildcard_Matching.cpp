#include <bits/stdc++.h>
using namespace std;

string removeStars(string &str)
{
    if (str.size() == 0)
        return "";
    string ans = "";
    ans += str[0];
    int i = 1;
    while (i < str.size())
    {
        while (ans[ans.size() - 1] == '*' and str[i] == '*')
            i++;
        if (i < str.size())
            ans += str[i];
        i++;
    }
    return ans;
}

bool isMatchMemo(string &s, string &p, int i1, int i2, vector<vector<int>> &dp)
{

    if (i1 == s.size() or i2 == p.size() or i2 == p.size() - 1 and p[i2] == '*')
    {
        if (i2 == p.size() - 1 and p[i2] == '*' or (i1 == s.size() and i2 == p.size()))
            return dp[i1][i2] = 1;
        else
            return dp[i1][i2] = 0;
    }

    char ch1 = s[i1], ch2 = p[i2];

    if (dp[i1][i2] != -1)
        return dp[i1][i2];

    if (ch1 == ch2 or ch2 == '?')
    {
        return dp[i1][i2] = isMatchMemo(s, p, i1 + 1, i2 + 1, dp);
    }
    else if (ch2 == '*')
    {
        bool res = false;
        res = res || isMatchMemo(s, p, i1, i2 + 1, dp) == 1;
        res = res || isMatchMemo(s, p, i1 + 1, i2, dp) == 1;
        return dp[i1][i2] = res ? 1 : 0;
    }
    else
    {
        return dp[i1][i2] = 0;
    }
}

bool isMatchTabu(string &s, string &p, int I1, int I2, vector<vector<int>> &dp)
{

    for (int i1 = s.size(); i1 >= 0; i1--)
    {
        for (int i2 = p.size(); i2 >= 0; i2--)
        {
            if (i1 == s.size() or i2 == p.size() or i2 == p.size() - 1 and p[i2] == '*')
            {
                if (i2 == p.size() - 1 and p[i2] == '*' or (i1 == s.size() and i2 == p.size()))
                {
                    dp[i1][i2] = 1;
                    continue;
                }
                else
                {
                    dp[i1][i2] = 0;
                    continue;
                }
            }

            char ch1 = s[i1], ch2 = p[i2];

            if (ch1 == ch2 or ch2 == '?')
            {
                dp[i1][i2] = dp[i1 + 1][i2 + 1]; // isMatchMemo(s, p, i1 + 1, i2 + 1, dp);
                continue;
            }
            else if (ch2 == '*')
            {
                bool res = false;
                res = res || dp[i1][i2 + 1] == 1; // isMatchMemo(s, p, i1, i2 + 1, dp) == 1;
                res = res || dp[i1 + 1][i2] == 1; // isMatchMemo(s, p, i1 + 1, i2, dp) == 1;
                dp[i1][i2] = res ? 1 : 0;
                continue;
            }
            else
            {
                dp[i1][i2] = 0;
                continue;
            }
        }
    }
    return dp[I1][I2];
}

bool isMatch(string s, string p)
{
    p = removeStars(p);
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int ans = isMatchMemo(s, p, 0, 0, dp);

    return ans == 1;
}

int main()
{
    return 0;
}