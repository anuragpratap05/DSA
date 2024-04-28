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

int coinChangeMemo(vector<int> &coins, int tar, int idx)
{
    if (tar == 0)
        return 0;
    int minDenominations = 1e7;
    for (int i = idx; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (tar - coin >= 0)
        {
            int recAns = coinChangeMemo(coins, tar - coin, i);
            if (recAns != 1e7 and recAns + 1 < minDenominations)
                minDenominations = recAns + 1;
        }
    }
    return minDenominations;
}

int coinChangeTabu(vector<int> &coins, int TAR)
{
    vector<int> dp(TAR + 1, 1e7);
    dp[0] = 0;
    for (int coin : coins)
    {
        // int minCoin = 1e7;
        for (int tar = 1; tar <= TAR; tar++)
        {
            if (tar - coin >= 0 && dp[tar - coin] + 1 < dp[tar])
            {
                dp[tar] = dp[tar - coin] + 1;
            }
        }
    }
    // for (int ele : dp)
    //     cout << ele << " ";
    // cout << endl;
    return dp[TAR];
}

int coinChange(vector<int> &coins, int amount)
{
    int minCoins = coinChangeTabu(coins, amount);
    return minCoins == 1e7 ? -1 : minCoins;
}

int main()
{
    int tar = 7;
    // int tar = 10;
    // vector<int> coins = {2, 3, 5, 7};
    vector<int> coins = {2, 4, 6};
    int ans = coinChange(coins, tar);
    cout << "ans--> " << ans << endl;
    return 0;
}