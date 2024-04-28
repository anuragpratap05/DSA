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

    for (int i = 0; i < n; i++)
    {
        int prevIncSub = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
                prevIncSub = max(prevIncSub, dp[j]);
        }
        dp[i] = prevIncSub + nums[i];
    }
    return dp;
}

int LongestBitonicSequence(vector<int> &nums)
{
    vector<int> forwDp = lengthOfLisTabu(nums);
    display(forwDp);
    reverse(nums.begin(), nums.end());
    vector<int> backDp = lengthOfLisTabu(nums);
    reverse(backDp.begin(), backDp.end());
    reverse(nums.begin(), nums.end());
    display(backDp);
    int maxSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxSum = max(maxSum, (forwDp[i] + backDp[i]) - nums[i]);
    }
    cout << "maxSum-> " << maxSum << endl;
    return maxSum;
}

int maxSumBS(int arr[], int n)
{
    vector<int> nums;
    for (int i = 0; i < n; i++)
        nums.push_back(arr[i]);
    return LongestBitonicSequence(nums);
}

int main()
{
    vector<int> nums = {1,
                        15,
                        51,
                        45,
                        33,
                        100,
                        12,
                        18,
                        9};
    LongestBitonicSequence(nums);
    return 0;
}