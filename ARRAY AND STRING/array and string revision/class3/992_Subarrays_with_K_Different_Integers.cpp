#include<bits/stdc++.h>
using namespace std;

int subarraysWith_atmost_KDistinct(vector<int>& nums, int k)
{
    vector<int>freq(20001,0);
    int i=0;
    int n=nums.size();
    int p=0;
    int c=0;
    int len=0;
    while(i<n)
    {
        int no=nums[i];
        if(freq[no]==0)
        {
            c++;
        }
        freq[no]++;
        i++;
        while(c>k)
        {
            int nno=nums[p];
            freq[nno]--;
            if(freq[nno]==0)
            {
                c--;
            }
            p++;
        }
        len+=i-p;
    }
    return len;
}


int subarraysWithKDistinct(vector<int>& nums, int k)
{
    int ans= subarraysWith_atmost_KDistinct(nums,k)-subarraysWith_atmost_KDistinct(nums,k-1);
    return  ans;

}

int main()
{
    vector<int>nums = {1,2,1,2,3};
    int  k = 2;
    cout<<subarraysWith_atmost_KDistinct(nums,k);
    return 0;
}