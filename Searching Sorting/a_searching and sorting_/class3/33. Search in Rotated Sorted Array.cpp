#include<bits/stdc++.h>
using namespace std;


int search(vector<int>& nums, int target)
{
    int n=nums.size();
    int si=0;
    int ei=n-1;
    while(si<=ei)
    {
        int mid=(si+ei)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        if(nums[si]<=nums[mid])
        {
            if(nums[si]<= target and nums[mid]>=target )//nums[mid-1]>=target then segmentation fault,  nums= [1], target =2
            {
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        else
        {
            if(nums[mid+1]<=target and nums[ei]>=target)
            {
                si=mid+1;
            }
            else
            {
                ei=mid-1;
            }
        }

    }   
    return -1;     
}

int main()
{
    return 0;
}