#include<bits/stdc++.h>
using namespace std;


bool search(vector<int>& nums, int target) {
        int n=nums.size();
    int si=0;
    int ei=n-1;
    while(si<=ei)
    {
        int mid=(si+ei)/2;
        if(nums[mid]==target or nums[si]==target)
        {
            return true;
        }
        if(nums[si]<nums[mid])
        {
            if(nums[si]<= target and nums[mid]>target)
            {
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        else if(nums[mid]<nums[ei])
        {
            if(nums[mid]<=target and nums[ei]>=target)
            {
                si=mid+1;
            }
            else
            {
                ei=mid-1;
            }
        }
        else
        {
            si++;
        }

    }   
    return false;
    }

int main()
{
    return 0;
}