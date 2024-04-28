#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

int minCutMemo(string &s, int si, int ei, vector<int> &dp, vector<vector<bool>> &pdp)
{
    if (si == s.size())
        return dp[si] = -1;
    if (dp[si] != -1)
        return dp[si];

    int minCuts = 1e8;
    for (int cut = si; cut <= ei; cut++)
    {
        if (pdp[si][cut])
            minCuts = min(minCuts, minCutMemo(s, cut + 1, ei, dp, pdp) + 1);
    }
    return dp[si] = minCuts;
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
                dp[i][j] = true;
            else if (gap == 1)
                dp[i][j] = s[i] == s[j];
            else
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
        }
    }
    vector<int> mainDp(n + 1, -1);
    return minCutMemo(s, 0, s.size() - 1, mainDp, dp);
}

int main()
{
    return 0;
}