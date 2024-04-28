#include <bits/stdc++.h>
using namespace std;

bool canPartitionMemo(vector<int> &nums, int tar, int idx, vector<vector<int>> &dp)
{
    if (idx == nums.size() or tar == 0)
        return dp[idx][tar] = tar == 0 ? true : false;
    if (dp[idx][tar] != -1)
        return dp[idx][tar];
    bool found = false;
    if (tar - nums[idx] >= 0)
        found = found || canPartitionMemo(nums, tar - nums[idx], idx + 1, dp);
    found = found || canPartitionMemo(nums, tar, idx + 1, dp);
    return dp[idx][tar] = found;
}

bool canPartition(vector<int> &nums)
{
    int arrSum = 0;
    for (int ele : nums)
        arrSum += ele;
    if (arrSum % 2 != 0)
        return false;
    int tar = arrSum / 2, n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));

    return canPartitionMemo(nums, tar, 0, dp);
}

int main()
{
    vector<int> nums = {2, 3, 5};
    bool ans = canPartition(nums);
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}