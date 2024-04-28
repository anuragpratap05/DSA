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
    int maxPalindrome;
    if (s[si] != s[ei])
        maxPalindrome = max(longestPalindromeSubseqHelp(s, si + 1, ei, dp), longestPalindromeSubseqHelp(s, si, ei - 1, dp));
    else
        maxPalindrome = 2 + longestPalindromeSubseqHelp(s, si + 1, ei - 1, dp);
    return dp[si][ei] = maxPalindrome;
}

int longestPalindromeSubseqTabu(string s, vector<vector<int>> &dp)
{
    int n = s.size();
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            if (si >= ei)
            {
                dp[si][ei] = si == ei ? 1 : 0;
                continue;
            }

            int maxPalindrome;
            if (s[si] != s[ei])
                maxPalindrome = max(dp[si + 1][ei], dp[si][ei - 1]);
            else
                maxPalindrome = 2 + dp[si + 1][ei - 1];
            dp[si][ei] = maxPalindrome;
        }
    }
    return dp[0][s.size() - 1];
}

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return longestPalindromeSubseqHelp(s, 0, s.size() - 1, dp);
}

int main()
{
    string s = "aecdabadce";
    cout << "ans--> " << longestPalindromeSubseq(s);
    return 0;
}