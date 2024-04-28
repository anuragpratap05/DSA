#include <bits/stdc++.h>
using namespace std;

int kPartitions(int n, int k, vector<vector<int>> &dp)
{
    if (k == 1 or n == k or k > n)
        return dp[n][k] = k > n ? 0 : 1;
    if (dp[n][k] != -1)
        return dp[n][k];

    int ownSet = kPartitions(n - 1, k - 1, dp);

    int sharedSet = kPartitions(n - 1, k, dp);

    return dp[n][k] = ownSet + (sharedSet * k);
}

int kPartitionsTabu(int N, int K, vector<vector<int>> &dp)
{
    for (int n = 1; n < dp.size(); n++)
    {
        for (int k = 1; k < dp[0].size(); k++)
        {
            if (k == 1 or n == k or k > n)
            {
                dp[n][k] = k > n ? 0 : 1;
                continue;
            }

            int ownSet = dp[n - 1][k - 1];
            // kPartitions(n - 1, k - 1, dp);

            int sharedSet = dp[n - 1][k];

            dp[n][k] = ownSet + (sharedSet * k);
        }
    }
    return dp[N][K];
}

int main()
{
    int n = 10, k = 4;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    int ans = kPartitionsTabu(n, k, dp);
    cout << "ans--> " << ans << endl;
    return 0;
}