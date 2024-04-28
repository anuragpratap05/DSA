#include<bits/stdc++.h>
using namespace std;

vector<int> twoSumErr(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int si = 0;
    int ei = nums.size() - 1;
    while(si!=ei)
    {
        if(nums[si]+nums[ei]==target)
        {
            return {si, ei};
        }
        else if (nums[si] + nums[ei] > target)
        {
            ei--;
        }
        else
        {
            si++;
        }
    }
    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size();i++)
    {
        int ele = nums[i];
        mp[ele] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if(mp.find(target-ele)!=mp.end() and mp[target-ele]!=i)
        {
            return {i, mp[target - ele]};
        }
    }
    return {-1, -1};
}

int main()
{
    return 0;
}