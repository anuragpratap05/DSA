#include <bits/stdc++.h>
using namespace std;

int maximum(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        return INT_MIN;
    }
    // int maxi=INT_MIN;
    int ans = maximum(nums, idx + 1);
    return max(ans, nums[idx]);
}
int minimum(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        return INT_MIN;
    }
    // int maxi=INT_MIN;
    int ans = maximum(nums, idx + 1);
    return max(ans, nums[idx]);
}
bool find(vector<int> &nums, int idx, int data)
{
    if(idx==nums.size())
    {
        return false;
    }
    
    return nums[idx]==data or find(nums, idx + 1, data);
}
int first_idx(vector<int> &nums, int idx,int data)
{
    if (idx == nums.size())
    {
        return -1;
    }
    // if (nums[idx] == data)
    // {
    //     return idx;
    // }
    // int ans=first_idx(nums,idx+1,data);

    return nums[idx] == data ? idx : first_idx(nums, idx + 1, data);
}
int last_idx(vector<int> &nums, int idx,int data)
{
    if (idx == nums.size())
    {
        return -1;
    }
    int ans=last_idx(nums,idx+1,data);
    if(ans!=-1)
    {
        return ans;
    }
    return nums[idx]==data?idx:-1;
}

int main()
{
    vector<int> vec = {1, 4, 2, 4, 6, 7, 2, 7, 8};
    // if (find(vec, 0, 9))
    // {
    //     cout<<"found";
    // }
    // else
    // {
    //     cout<<"not found";
    // }

    cout << last_idx(vec, 0, 2);

    return 0;
}