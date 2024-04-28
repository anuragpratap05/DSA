#include<bits/stdc++.h>
using namespace std;


bool is_valid_window(int a,int b)
{
    //if(idx1==idx2 or nums[idx1]<nums[idx2])
    return (a<=b?true:false);
}

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
        else if(is_valid_window(nums[si],nums[mid]))
        {
            if(nums[si]<= target and nums[mid]>target)
            {
                ei=mid-1;
            }
            else
            {
                si=mid+1;
            }
        }
        else{

            if(nums[mid]<target and nums[ei]>=target)
            {
                si=mid+1;
            }
            else{
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