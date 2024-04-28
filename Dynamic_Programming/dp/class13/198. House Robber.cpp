#include <bits/stdc++.h>
using namespace std;

int robMemo(vector<int> &nums, int si, vector<int> &dp)
{
    if (si >= nums.size() - 1)
        return si == nums.size() - 1 ? nums[si] : 0;
    if (dp[si] != -1)
        return dp[si];

    int include = robMemo(nums, si + 2, dp) + nums[si];
    int exclude = robMemo(nums, si + 1, dp);
    return dp[si] = max(include, exclude);
}

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() - 1, -1);
    return robMemo(nums, 0, dp);
}

int main()
{
    return 0;
}