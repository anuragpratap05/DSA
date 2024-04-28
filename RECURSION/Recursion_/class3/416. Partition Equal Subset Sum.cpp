#include <bits/stdc++.h>
using namespace std;
//TLE
bool equal_set(vector<int> &nums, int sum1, int sum2, int idx)
{
    if (idx == nums.size())
    {
        if (sum1 == sum2)
        {

            return true;
        }
        return false;
    }

    return equal_set(nums, sum1 + nums[idx], sum2,  idx + 1) or equal_set(nums, sum1, sum2 + nums[idx], idx + 1);
}
bool canPartition(vector<int> &nums)
{
    if(nums.size()<2)
    {
        return false;
    }

    return equal_set(nums,0,0,0);
}

int main()
{
    return 0;
}