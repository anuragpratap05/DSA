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

int totalWays(int n, int i, vector<int> &dp)
{
    if (i == n)
        return dp[i] = 1;
    int ways = 0;
    if (dp[i] != -1)
        return dp[i];
    for (int jump = 1; jump <= 6; jump++)
    {
        if (i + jump <= n)
            ways += totalWays(n, i + jump, dp);
        else
            break;
    }
    return dp[i] = ways;
}

int totalWaysTabu(int n, int i, vector<int> &dp)
{

    for (int i = n; i >= 0; i--)
    {
        if (i == n)
        {
            dp[i] = 1;
            continue;
        }
        int ways = 0;

        for (int jump = 1; jump <= 6; jump++)
        {
            if (i + jump <= n)
                ways += dp[i + jump];
            else
                break;
        }
        dp[i] = ways;
    }
    return dp[0];
}

int main()
{
    int n = 30;
    vector<int> dp(n + 1, -1);
    cout << "ways--> " << totalWaysTabu(n, 0, dp) << endl;
    
    return 0;
}