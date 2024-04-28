#include <bits/stdc++.h>
using namespace std;

int lengthOfLISHelp(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int val = nums[i];
        int prevMax = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < val and dp[j] > prevMax)
                prevMax = dp[j];
        }
        dp[i] = prevMax + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int lengthOfLIS(vector<int> &nums)
{
    return lengthOfLISHelp(nums);
}

int main()
{
    return 0;
}