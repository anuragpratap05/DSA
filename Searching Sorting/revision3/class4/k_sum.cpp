#include <bits/stdc++.h>
using namespace std;

void twoSum(vector<int> &nums, int s, int e, long long tar, vector<vector<int>> &ans, vector<int> &pEles)
{
    while (s < e)
    {
        int sum = nums[s] + nums[e];
        if (sum == tar)
        {
            vector<int> temp = {};
            for (int e1 : pEles)
            {
                temp.push_back(e1);
            }
            temp.push_back(nums[s]);
            temp.push_back(nums[e]);
            ans.push_back(temp);
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

void kSum(vector<int> &nums, long long target, int k, vector<vector<int>> &ans, int i, vector<int> &pEles)
{
    int n = nums.size();
    if (k == 2)
    {
        twoSum(nums, i, n - 1, target, ans, pEles);
        return;
    }
    while (i < n - (k - 1))
    {
        int curEle = nums[i];
        pEles.push_back(curEle);
        kSum(nums, target - curEle, k - 1, ans, i + 1, pEles);
        pEles.pop_back();
        i++;
        while (i < n and nums[i] == curEle)
        {
            i++;
        }
    }
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> pEles;
    int k = 4;
    sort(nums.begin(), nums.end());
    kSum(nums, target, 4, ans, 0, pEles);
    return ans;
}

int main()
{
    return 0;
}