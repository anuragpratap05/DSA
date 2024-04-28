#include <bits/stdc++.h>
using namespace std;

int getProduct(vector<int> &nums, int si, int cut, int ei)
{
    si--;
    ei++;
    int leftVal = si < 0 ? 1 : nums[si];
    int midVal = nums[cut];
    int rightVal = ei == nums.size() ? 1 : nums[ei];
    return leftVal * midVal * rightVal;
}

int maxCoinsMemo(vector<int> &nums, int si, int ei, vector<vector<int>> &dp)
{
    if (si == ei)
        return dp[si][ei] = getProduct(nums, si, si, si);
    if (dp[si][ei] != -1)
        return dp[si][ei];
    int maxVal = 0;
    for (int cut = si; cut <= ei; cut++)
    {
        int leftVal = si <= cut - 1 ? maxCoinsMemo(nums, si, cut - 1, dp) : 0;
        int rightVal = cut + 1 <= ei ? maxCoinsMemo(nums, cut + 1, ei, dp) : 0;
        maxVal = max(maxVal, leftVal + rightVal + getProduct(nums, si, cut, ei));
    }
    return dp[si][ei] = maxVal;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return maxCoinsMemo(nums, 0, n - 1, dp);
}

int main()
{
    vector<int> nums = {1, 5};
    int ans = maxCoins(nums);
    cout << "ans-->" << ans << endl;
    return 0;
}