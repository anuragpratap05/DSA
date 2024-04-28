#include <bits/stdc++.h>
using namespace std;

void twoSum(vector<int> &nums, int s, int e, long long tar, vector<vector<int>> &ans, int fEle, int sEle)
{
    while (s < e)
    {
        int sum = nums[s] + nums[e];
        if (sum == tar)
        {
            ans.push_back({fEle, sEle, nums[s], nums[e]});
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

vector<vector<int>> threeSum(vector<int> &nums, vector<vector<int>> &ans, int fEle, int i, long long tar)
{
    int n = nums.size();
    // int i = 0;
    // vector<vector<int>> ans;
    // sort(nums.begin(), nums.end());
    while (i < n - 2)
    {
        int curEle = nums[i];
        twoSum(nums, i + 1, n - 1, tar - curEle, ans, fEle, curEle);
        i++;
        while (i < n and nums[i] == curEle)
        {
            i++;
        }
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    int n = nums.size();
    int i = 0;
    while (i < n - 3)
    {
        int curEle = nums[i];
        threeSum(nums, ans, curEle, i + 1, target - curEle);
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
    return 0;
}