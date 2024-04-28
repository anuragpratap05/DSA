#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ei,si,len;
        ei=si=len=0;
        while(ei<n)
        {
            if(nums[ei]==0)
            {
                ei++;
                si=ei;
                
            }
            else{
                ei++;
            }
            len=max(len,ei-si);
        }
        return len;
    }
};

int main()
{
    return 0;
}