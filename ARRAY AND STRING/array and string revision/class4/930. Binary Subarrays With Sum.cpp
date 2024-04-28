#include<bits/stdc++.h>
using namespace std;

int atmost_sum(vector<int>& nums, int goal)
{
    int n=nums.size();
    int p=0;
    int i=0;
    int sum=0;
    int len=0;
    while(i<n)
    {
        sum+=nums[i];
        i++;
        while(sum>goal)
        {
            
            sum-=nums[p];
            p++;
        }
        len+=i-p;
    }
    return len;
}


int numSubarraysWithSum(vector<int>& nums, int goal)
{
    int a=atmost_sum(nums,goal);
    int b=atmost_sum(nums,goal-1);
    return a-b;

}

int main()
{
    return 0;
}