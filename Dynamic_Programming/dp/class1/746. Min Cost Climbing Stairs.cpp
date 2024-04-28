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

int minCostClimbingStairshelp(vector<int> &cost, int i, vector<int> &dp)
{
    if (i > cost.size())
        return 1e7;
    if (i == cost.size())
    {
        return dp[i] = 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int oneStep = minCostClimbingStairshelp(cost, i + 1, dp);
    int twoStep = minCostClimbingStairshelp(cost, i + 2, dp);

    int minCost = min(oneStep, twoStep) + cost[i];
    return dp[i] = minCost;
}

int minCostClimbingStairshelpTabu(vector<int> &cost, int i, vector<int> &dp)
{
    for (int i = cost.size(); i >= 0; i--)
    {

        if (i == cost.size() or i == cost.size() - 1)
        {
            dp[i] = i == cost.size() ? 0 : cost[i];
            continue;
        }

        int oneStep = dp[i + 1];
        int twoStep = dp[i + 2];

        int minCost = min(oneStep, twoStep) + cost[i];
        dp[i] = minCost;
    }
    
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    minCostClimbingStairshelp(cost, 0, dp);
    return min(dp[0], dp[1]);
}

int main()
{
    return 0;
}