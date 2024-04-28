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

int main()
{
    return 0;
}