#include <bits/stdc++.h>
using namespace std;

int totalSubaraysSumsTarget(vector<int> &nums, int target)
{
    int cumSum = 0, cnt = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (int ele : nums)
    {
        cumSum += ele;
        if (mp.find(cumSum - target) != mp.end())
        {
            cnt += mp[cumSum - target];
        }

        mp[cumSum]++;
    }
    return cnt;
}

int subarraySum(vector<int> &nums, int k)
{
    return totalSubaraysSumsTarget(nums, k);
}

int main()
{
    return 0;
}