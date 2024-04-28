#include <bits/stdc++.h>
using namespace std;

int numDecodingsHelp(string &s, int idx, vector<int> &dp)
{
    if (idx == s.size() or s[idx] == '0')
        return idx == s.size() ? 1 : 0;
    if (dp[idx] != -1)
        return dp[idx];

    int singleAns = numDecodingsHelp(s, idx + 1, dp);
    int doubleAns = 0;
    if (idx + 1 < s.size())
    {
        int twoDigitNum = (s[idx] - '0') * 10 + s[idx + 1] - '0';
        if (twoDigitNum <= 26)
            doubleAns = numDecodingsHelp(s, idx + 2, dp);
    }
    return dp[idx] = singleAns + doubleAns;
}

int numDecodings(string s)
{

    vector<int> dp(s.size() + 1, -1);
    return numDecodingsHelp(s, 0, dp);
}

int main()
{
    char ch1 = '2';
    char ch2 = '3';
    int num = (ch1 - '0') * 10 + ch2 - '0';
    int ans = num + 1;
    cout << ans << endl;
    return 0;
}