#include <bits/stdc++.h>
using namespace std;

int perfectInsertPosofEle(vector<int> &nums, int ele)
{
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ele <= nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    if (s - 1 >= 0 and nums[s] == ele)
    {
        return s - 1;
    }
    return s;
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> vec;
    vec.push_back(nums[0]);
    for (int i = 1; i < nums.size();i++)
    {
        int idx = perfectInsertPosofEle(vec, nums[i]);
        if (idx == vec.size())
        {
            vec.push_back(nums[i]);
        }
        else
        {
            vec[idx] = nums[i];
        }
    }
    return vec.size();
}

int main()
{
    return 0;
}