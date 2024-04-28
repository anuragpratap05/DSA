#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairsMemo(vector<int> &cost, int idx, vector<int> &dp)
{
    if (idx >= cost.size())
        return dp[idx] = 0;
    if (dp[idx] != -1)
        return dp[idx];
    int oneStep = minCostClimbingStairsMemo(cost, idx + 1, dp);
    int twoStep = minCostClimbingStairsMemo(cost, idx + 2, dp);
    return dp[idx] = cost[idx] + min(oneStep, twoStep);
}

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp(cost.size() + 2, -1);
    return min(minCostClimbingStairsMemo(cost, 0, dp), minCostClimbingStairsMemo(cost, 1, dp));
}

int main()
{
    return 0;
}