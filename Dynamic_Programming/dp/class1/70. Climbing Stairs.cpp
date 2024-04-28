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

int climbStairsHelp(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0 or n == 1)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];

    int ans = climbStairsHelp(n - 1, dp) + climbStairsHelp(n - 2, dp);
    return dp[n] = ans;
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return climbStairsHelp(n, dp);
}

int main()
{
    return 0;
}