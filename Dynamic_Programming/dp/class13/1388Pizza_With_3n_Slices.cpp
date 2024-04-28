#include <bits/stdc++.h>
using namespace std;

int robMemo(vector<int> &nums, int si, int ei, int k, vector<vector<int>> &dp)
{
    if (si > ei or k == 0)
        return 0;
    if (dp[si][k] != -1)
        return dp[si][k];

    int include = robMemo(nums, si + 2, ei, k - 1, dp) + nums[si];
    int exclude = robMemo(nums, si + 1, ei, k, dp);
    return dp[si][k] = max(include, exclude);
}

int maxSizeSlices(vector<int> &slices)
{

    int n = slices.size();
    int k = n / 3;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    vector<vector<int>> dp2(n, vector<int>(k + 1, -1));

    return max(robMemo(slices, 0, n - 2, k, dp), robMemo(slices, 1, n - 1, k, dp2));
}

int main()
{
    vector<int> slices = {1, 2, 3, 4, 5, 6};
    int maxMoney = maxSizeSlices(slices);
    cout << "Max Money = " << maxMoney << endl;
    return 0;
}