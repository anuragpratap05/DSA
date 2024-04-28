#include <bits/stdc++.h>
using namespace std;

void displayDp(vector<vector<int>> &dp)
{
    for (vector<int> &vec : dp)
    {
        for (int ele : vec)
            cout << ele << " ";
        cout << endl;
    }
    cout << endl;
}

int combinationMultiCoinHelp(vector<int> &coins, int tar, int idx, vector<vector<int>> &dp)
{
    if (tar == 0)
    {

        return dp[tar][idx] = 1;
    }
    if (dp[tar][idx] != -1)
        return dp[tar][idx];
    int ways = 0;
    for (int i = idx; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (tar - coin >= 0)
        {
            ways += combinationMultiCoinHelp(coins, tar - coin, i, dp);
        }
    }
    return dp[tar][idx] = ways;
}

int combinationMultiCoinTabu(vector<int> &coins, int TAR)
{
    vector<int> dp(TAR + 1, 0);
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int tar = 1; tar <= TAR; tar++)
        {
            if (tar - coin >= 0)
                dp[tar] += dp[tar - coin];
        }
    }
    for (int ele : dp)
        cout << ele << " ";
    cout << endl;
    return dp[TAR];
}

int combinationMultiCoin(vector<int> &coins, int tar)
{
    vector<vector<int>> dp(tar + 1, vector<int>(coins.size(), -1));
    int ans = combinationMultiCoinHelp(coins, tar, 0, dp);
    // int ans = combinationMultiCoinTabu(coins, tar);
    // displayDp(dp);
    return ans;
}

int recCalls = 0;

int permunationMultiCoinHelp(vector<int> &coins, int tar, vector<int> &dp)
{
    recCalls++;
    if (tar == 0)
    {
        return dp[tar] = 1;
    }
    if (dp[tar] != -1)
        return dp[tar];
    int ways = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        if (tar - coin >= 0)
        {
            ways += permunationMultiCoinHelp(coins, tar - coin, dp);
        }
    }
    return dp[tar] = ways;
}

int permunationMultiCoinTabu(vector<int> &coins, int TAR, vector<int> &dp)
{
    for (int tar = 0; tar <= TAR; tar++)
    {
        if (tar == 0)
        {
            dp[tar] = 1;
            continue;
        }

        int ways = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];
            if (tar - coin >= 0)
            {
                ways += dp[tar - coin];
            }
        }
        dp[tar] = ways;
    }

    return dp[TAR];
}

int permunationMultiCoin(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1, -1);
    // int ans = permunationMultiCoinHelp(coins, tar, dp);
    int ans = permunationMultiCoinTabu(coins, tar, dp);
    // cout << "recCalls--> " << recCalls << endl;
    for (int ele : dp)
        cout << ele << ' ';
    return ans;
}

int main()
{
    // int tar = 10;
    int tar = 4;
    // vector<int> coins = {2, 3, 5, 7};
    vector<int> coins = {1, 2, 3};
    int ways = combinationMultiCoin(coins, tar);
    // int ways = permunationMultiCoin(coins, tar);
    cout << "ways--> " << ways << endl;
    return 0;
}