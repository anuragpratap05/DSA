#include <bits/stdc++.h>
using namespace std;

int lengthOfLisTabu(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int prevIncSub = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
                prevIncSub = max(prevIncSub, dp[j]);
        }
        dp[i] = prevIncSub + nums[i];
        ans = max(ans, dp[i]);
    }
    return ans;
}
int maxSumIS(int arr[], int n)
{
    // Your code goes here
    vector<int> nums;
    for (int i = 0; i < n; i++)
        nums.push_back(arr[i]);
    return lengthOfLisTabu(nums);
}

int main()
{
    return 0;
}