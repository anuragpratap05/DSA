#include <bits/stdc++.h>
using namespace std;

int isMatchMemo(string s, string p, int si, int pi, vector<vector<int>> &dp)
{
    if (si < 0 and pi < 0)
        return 1;
    if (si < 0 or pi < 0)
    {

        if (pi < 0)
            return 0;
        while (pi >= 0)
        {
            // cout << "aya" << endl;
            if (p[pi] != '*')
                return 0;
            pi -= 2;
        }
        return 1;
    }

    if (dp[si][pi] != -1)
        return dp[si][pi];
    char ch1 = s[si];
    char ch2 = p[pi];

    if (ch1 == ch2 or ch2 == '.')
        return dp[si][pi] = isMatchMemo(s, p, si - 1, pi - 1, dp);
    else if (ch2 == '*')
    {
        bool res = false;
        if (p[pi - 1] == ch1 or p[pi - 1] == '.')
            res = res || isMatchMemo(s, p, si - 1, pi, dp);
        res = res || isMatchMemo(s, p, si, pi - 2, dp);
        return dp[si][pi] = res;
    }
    else
        return dp[si][pi] = 0;
}

bool isMatch(string s, string p)
{
    vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
    return isMatchMemo(s, p, s.size() - 1, p.size() - 1, dp);
}

int main()
{
    string s = "a";
    string p = ".a";
    bool ans = isMatch(s, p);
    if (ans)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}