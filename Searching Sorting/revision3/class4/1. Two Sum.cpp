#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (mp.find(target - ele) != mp.end() and mp[target - ele] != i)
        {
            return {i, mp[target - ele]};
        }
    }
    return {};
}

int main()
{
    return 0;
}