#include <bits/stdc++.h>
using namespace std;

int vectorSum(vector<int> &vec)
{
    int sum = 0;
    for (int ele : vec)
        sum += ele;
    return sum;
}

bool calculateSum(vector<vector<int>> &ans)
{
    int expectedSum = vectorSum(ans[0]);
    for (int i = 1; i < ans.size(); i++)
    {
        int sum = vectorSum(ans[i]);
        if (sum != expectedSum)
            return false;
    }
    return true;
}

bool canPartitionKSubsets(vector<int> &nums, int k, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        return calculateSum(ans);
    }
    int ele = nums[idx];
    for (vector<int> &vec : ans)
    {
        vec.push_back(ele);
        bool x = canPartitionKSubsets(nums, k, idx + 1, ans);
        if (x)
            return true;
        vec.pop_back();
        if (vec.size() == 0)
            break;
    }
    return false;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    vector<vector<int>> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back({});
    }

    return canPartitionKSubsets(nums, k, 0, ans);
}

int main()
{
    return 0;
}