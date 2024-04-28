#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> remainders(k,0);
        remainders[0]=1;
        
        int ei,si,sum,ans;
        ei=si=sum=ans=0;
        int rem;
        
        while(ei<n)
        {
            sum+=nums[ei++];
            rem=(sum%k+k)%k;
            ans+=remainders[rem];
            remainders[rem]++;
        }
        return ans;
        
    }
};

int main()
{
    return 0;
}