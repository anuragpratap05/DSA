#include <bits/stdc++.h>
using namespace std;
void display(vector<int> &dp)
{
    for (int ele : dp)
    {
        cout << ele << ' ';
    }
    cout << endl;
}

int lengthOfLISHelp(vector<int> &nums, int idx, vector<int> &dp)
{
    if (dp[idx] != -1)
        return dp[idx];
    int maxLen = 1;
    for (int i = idx + 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[idx])
        {
            int recAns = lengthOfLISHelp(nums, i, dp);
            if (recAns + 1 > maxLen)
                maxLen = recAns + 1;
        }
    }
    return dp[idx] = maxLen;
}

int lengthOfLisTabu(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int prevIncSub = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
                prevIncSub = max(prevIncSub, nums[j]);
        }
        dp[i] = prevIncSub + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxLen = max(maxLen, lengthOfLISHelp(nums, i, dp));
    }
    return maxLen;
    display(dp);
}

int main()
{
    vector<int> nums = {6, 5, 3, 2, 1, 6, 8, 9, 2, 1, 5, 11};
    lengthOfLIS(nums);
    return 0;
}