#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int atmost_k_distinct(vector<int>& nums,int k)
{
    int n=nums.size();
    int ei,si;
    ei=si=0;
    int c=0;
    int count=0;
    //vector<int> freq(8,0);
    while(ei<n)
    {
        //cout<<nums[ei]<<" ";
        //cout<<"freq[3]="<<freq[3]<<endl;
        if(nums[ei]%2!=0)
        {
           // cout<<"aya";
            c++;
            //cout<<"c="<<c<<endl;
        }
        //freq[nums[ei]]++;
        ei++;
        
        while(c>k)
        {
            //cout<<"aya";
            //freq[nums[si]]--;
            if(nums[si]%2!=0)
            {
                c--;
            }
            si++;
        }
        count+=ei-si;
    }
        return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost_k_distinct(nums,k)-atmost_k_distinct(nums,k-1);
    }
};

int main()
{
    return 0;
}