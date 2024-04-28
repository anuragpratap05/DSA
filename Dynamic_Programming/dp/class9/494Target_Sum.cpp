#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &dp)
{
    for (int ele : dp)
        cout << ele << " ";
    cout << endl;
}

int targetSum(vector<int> &nums, int TAR)
{
    int n = nums.size();
    vector<int> prev(TAR + 1, 0);
    prev[0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(TAR + 1, 0);
        for (int tar = 0; tar <= TAR; tar++)
        {
            curr[tar] += prev[tar];
            if (tar - nums[i] >= 0)
                curr[tar] += prev[tar - nums[i]];
        }
        // display(curr);
        prev = curr;
    }
    return prev[TAR];
}

int canPartitionMemo(vector<int> &nums, int tar, int idx, vector<vector<int>> &dp)
{
    if (idx == nums.size())
    {
        if (tar == 0)
            return 1;
        return 0;
    }
    if (dp[idx][tar] != -1)
        return dp[idx][tar];
    int cnt = 0;
    if (tar - nums[idx] >= 0)
        cnt += canPartitionMemo(nums, tar - nums[idx], idx + 1, dp);
    cnt += canPartitionMemo(nums, tar, idx + 1, dp);
    return dp[idx][tar] = cnt;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int arrSum = 0, n = nums.size();
    for (int ele : nums)
        arrSum += ele;

    int num = (arrSum - target);
    if (num % 2 != 0)
        return 0;
    int tar = num / 2;
    // cout << "tar-> " << tar << endl;
    if (tar < 0)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));

    int noOfWays = canPartitionMemo(nums, tar, 0, dp);
    return noOfWays;
}

int main()
{
    // vector<int> nums = {2, 2, 4, 3, 6};
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = -5;
    int ans = findTargetSumWays(nums, target);
    cout << "ans-->" << ans << endl;

    // vector<int> nums = {1, 0};
    // int TAR = 0;
    // int ans = targetSum(nums, TAR);
    // cout << "ans-->" << ans << endl;

    return 0;
}