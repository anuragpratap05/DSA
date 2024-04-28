#include<bits/stdc++.h>
using namespace std;
bool is_valid_window(int a,int b)
{
    //if(idx1==idx2 or nums[idx1]<nums[idx2])
    return (a<=b?true:false);
}

int search(vector<int>& nums)
{

    int n=nums.size();
    int si=0;
    int mini=INT_MAX;
    int ei=n-1;
    while(si<=ei)
    {
        int mid=(si+ei)/2;
        // if(nums[mid]==target)
        // {
        //     return mid;
        // }
         if(is_valid_window(nums[si],nums[mid]))
        {
            mini=min(mini,nums[si]);
            si=mid+1;
        }
        else{

            mini=min(mini,nums[mid]);
            ei=mid-1;
        }
    }

    return mini;


}

int findMin(vector<int>& nums) {
        return search(nums);
    }

int main()
{
    return 0;
}