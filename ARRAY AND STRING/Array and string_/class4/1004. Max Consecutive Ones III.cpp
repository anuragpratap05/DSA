#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ei,si,len,c;
        ei=si=c=len=0;
        while(ei<n)
        {
            if(nums[ei]==0)
            {
                c++;
            }
            ei++;
            while(c>k)
            {
                if(nums[si]==0)
                {
                    c--;
                }
                si++;
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