#include <bits/stdc++.h>
using namespace std;



int robMemo(vector<int> &nums, int si, int ei, vector<vector<int>> &dp)
{
    if (si >= ei)
        return si == ei ? nums[si] : 0;
    if (dp[si][ei] != -1)
        return dp[si][ei];

    int include = robMemo(nums, si + 2, si == 0 ? ei - 1 : ei, dp) + nums[si];
    int exclude = robMemo(nums, si + 1, ei, dp);
    return dp[si][ei] = max(include, exclude);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return robMemo(nums, 0, n - 1, dp);
}

int main()
{
    vector<int> nums = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240};
    int maxMoney = rob(nums);
    cout << "Max Money = " << maxMoney << endl;
    return 0;
}