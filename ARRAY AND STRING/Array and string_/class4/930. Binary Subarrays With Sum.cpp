#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int atmost(vector<int>& nums, int goal)
    {
        int ei,si,c,len,sum;
        ei=si=len=c=sum=0;
        int n=nums.size();
        while(ei<n)
        {
            sum+=nums[ei++];
            
            while(sum>goal)
            {
                sum-=nums[si];
                si++;
            }
            len+=ei-si;
        }
        return len;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)- (goal>0?atmost(nums,goal-1):0);
    }
};

int main()
{
    return 0;
}