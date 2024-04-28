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

int longestPalindromeSubseqHelp(string &s, int si, int ei, vector<vector<int>> &dp)
{
    if (si >= ei)
        return dp[si][ei] = si == ei ? 1 : 0;
    if (dp[si][ei] != -1)
        return dp[si][ei];

    if (s[si] == s[ei])
        return dp[si][ei] = longestPalindromeSubseqHelp(s, si + 1, ei - 1, dp) + 2;
    else
        return dp[si][ei] = max(longestPalindromeSubseqHelp(s, si + 1, ei, dp), longestPalindromeSubseqHelp(s, si, ei - 1, dp));
}

int longestPalindromeSubseqTabu(string &s, int SI, int EI, vector<vector<int>> &dp)
{
    int n = s.size();
    for (int gap = 0; gap <= EI; gap++)
    {
        for (int si = SI, ei = gap; ei <= EI; si++, ei++)
        {
            if (si >= ei)
            {
                dp[si][ei] = si == ei ? 1 : 0;
                continue;
            }

            if (s[si] == s[ei])
            {
                dp[si][ei] = dp[si + 1][ei - 1] + 2;
            }
            else
            {
                dp[si][ei] = max(dp[si + 1][ei], dp[si][ei - 1]);
            }
        }
    }
    return dp[SI][EI];
}

string lpsBackEngine(vector<vector<int>> &dp, int si, int ei, string &s)
{
    if (si >= ei)
    {
        string base = "";
        if (si == ei)
            base += s[si];
        return base;
    }

    if (s[si] == s[ei])
        return s[si] + lpsBackEngine(dp, si + 1, ei - 1, s) + s[ei];
    else
    {
        if (dp[si][ei - 1] > dp[si + 1][ei])
            return lpsBackEngine(dp, si, ei - 1, s);
        else
            return lpsBackEngine(dp, si + 1, ei, s);
    }
}

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    int ans = longestPalindromeSubseqTabu(s, 0, s.size() - 1, dp);
    string subseq = lpsBackEngine(dp, 0, s.size() - 1, s);
    cout << "subseq--> " << subseq << endl;
    return ans;
}

int main()
{
    string s = "akfktamkftak";
    int maxLen = longestPalindromeSubseq(s);
    cout << "maxLen--> " << maxLen << endl;

    return 0;
}