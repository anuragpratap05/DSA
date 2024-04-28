#include <bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int> &nums, int target)
{
    int TAR = target;
    vector<long> dp(TAR + 1, 0);
    for (int tar = 0; tar <= TAR; tar++)
    {
        if (tar == 0)
        {
            dp[tar] = 1;
            continue;
        }

        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int coin = nums[i];
            if (tar - coin >= 0)
            {
                ways += dp[tar - coin];
            }
        }
        dp[tar] = ways;
    }

    return dp[TAR];
}

int main()
{
    return 0;
}