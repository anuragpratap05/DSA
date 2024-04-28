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

int longestCommonSubsequenceHelp(string &text1, string &text2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 or m == 0)
        return dp[n][m] = 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (text1[n - 1] == text2[m - 1])
        return dp[n][m] = longestCommonSubsequenceHelp(text1, text2, n - 1, m - 1, dp) + 1;
    else
        return dp[n][m] = max(longestCommonSubsequenceHelp(text1, text2, n - 1, m, dp), longestCommonSubsequenceHelp(text1, text2, n, m - 1, dp));
}

int longestCommonSubsequenceHelpTabu(string &text1, string &text2, int N, int M, vector<vector<int>> &dp)
{
    for (int n = 0; n <= N; n++)
    {
        for (int m = 0; m <= M; m++)
        {
            if (n == 0 or m == 0)
            {
                dp[n][m] = 0;
                continue;
            }

            if (text1[n - 1] == text2[m - 1])
                dp[n][m] = dp[n - 1][m - 1] + 1;
            else
                dp[n][m] = max(dp[n - 1][m], dp[n][m - 1]);
        }
    }
    return dp[N][M];
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return longestCommonSubsequenceHelp(text1, text2, n, m, dp);
}

int main()
{
    cout << "ans--> " << longestCommonSubsequence("akbacdef", "kace") << endl;
    return 0;
}