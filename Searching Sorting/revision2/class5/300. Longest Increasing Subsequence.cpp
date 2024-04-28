#include<bits/stdc++.h>
using namespace std;

int perfect_insert_pos(vector<int>& nums,int tar)
{
    int n=nums.size();
    int si=0;
    int ei=n-1;
    while(si<=ei)
    {
        int mid=(si+ei)/2;
        if(nums[mid]<=tar)
        {
            si=mid+1;
        }
        else
        {
            ei=mid-1;
        }

    }
    if(si-1>=0 and nums[si-1]==tar)
    {
        return si-1;
    }
    return si;
}
int lengthOfLIS(vector<int>& nums)
{
    vector<int>vec;
    int n=nums.size();
    int len=1;
    vec.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        int tar=nums[i];
        int idx=perfect_insert_pos(vec,tar);
        if(idx==vec.size())
        {
            len++;
            vec.push_back(tar);
        }
        else
        {
            vec[i]=tar;
        }

    }   
    return len;     
}

int main()
{
    return 0;
}