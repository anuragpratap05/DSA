#include<bits/stdc++.h>
using namespace std;




int findMin(vector<int>& nums)
{
    int n=nums.size();
    int ei=n-1;
    int si=0;
    while(si<=ei)
    {
        int mid=(si+ei)/2;
        int myval=nums[mid];
        int lval= (mid-1<0?INT_MAX:nums[mid-1]);
        int rval= (mid+1>=n?INT_MAX:nums[mid+1]);
        if(myval<lval and myval<rval)
        {
            return mid;
        }
        if(nums[si]<=nums[mid])
        {
            si=mid+1;
        }
        else
        {
            ei=mid-1;
        }
    }
    return -1;
}

int main() 
{
    return 0;
}