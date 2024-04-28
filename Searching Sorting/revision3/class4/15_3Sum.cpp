#include <bits/stdc++.h>
using namespace std;

void twoSum(vector<int> &nums, int s, int e, int tar, vector<vector<int>> &ans, int fEle)
{
    while (s < e)
    {
        int sum = nums[s] + nums[e];
        if (sum == tar)
        {
            ans.push_back({fEle, nums[s], nums[e]});
            s++;
            e--;
            while (s < e and nums[s] == nums[s - 1])
            {
                s++;
            }
            while (s < e and nums[e + 1] == nums[e])
            {
                e--;
            }
        }
        else if (sum < tar)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    while (i < n - 2)
    {
        int curEle = nums[i];
        twoSum(nums, i + 1, n - 1, 0 - curEle, ans, curEle);
        i++;
        while (i < n and nums[i] == curEle)
        {
            i++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-8, 5, 2, 7, 6, 3};
    threeSum(nums);
    return 0;
}