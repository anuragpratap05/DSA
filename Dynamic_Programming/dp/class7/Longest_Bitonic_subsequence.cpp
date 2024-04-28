#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &nums)
{
    for (int ele : nums)
        cout << ele << ' ';
    cout << endl;
}

vector<int> lengthOfLisTabu(vector<int> &nums)
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
        dp[i] = prevIncSub + 1;
        ans = max(ans, dp[i]);
    }
    return dp;
}

int LongestBitonicSequence(vector<int> &nums)
{
    vector<int> forwDp = lengthOfLisTabu(nums);
    // display(forwDp);
    reverse(nums.begin(), nums.end());
    vector<int> backDp = lengthOfLisTabu(nums);
    reverse(backDp.begin(), backDp.end());
    // display(backDp);
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxLen = max(maxLen, (forwDp[i] + backDp[i]) - 1);
    }
    // cout << "maxLen-> " << maxLen << endl;
    return maxLen;
}

int main()
{
    vector<int> nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 14};
    LongestBitonicSequence(nums);
    return 0;
}