#include <bits/stdc++.h>
using namespace std;

int mincutMemo(string &s, int si, vector<vector<bool>> &dp, vector<vector<int>> &mainDp)
{
    if (si == s.size())
        return -1;
    if (mainDp[si][s.size() - 1] != -1)
        return mainDp[si][s.size() - 1];

    int min_cut = 1e9;
    for (int cut = si; cut < s.size(); cut++)
    {
        if (dp[si][cut])
        {
            int recCut = mincutMemo(s, cut + 1, dp, mainDp);
            min_cut = min(min_cut, recCut + 1);
        }
    }
    return mainDp[si][s.size() - 1] = min_cut;
}

int minCut(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (gap == 1)
            {
                dp[i][j] = s[i] == s[j];
            }
            else
            {
                dp[i][j] = s[i] == s[j] and dp[i + 1][j - 1];
            }
        }
    }

    vector<vector<int>> mainDp(n, vector<int>(n, -1));
    return mincutMemo(s, 0, dp, mainDp);
}

int main()
{
    string s = "kaakaf";
    int minCuts = minCut(s);
    cout << "min Cuts = " << minCuts << endl;
    return 0;
}