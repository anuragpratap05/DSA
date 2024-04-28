#include<bits/stdc++.h>
using namespace std;


int subarraysDivByK(vector<int>& nums, int k)
{
    long long sum=0;
    vector<int> freq(10001,0);
    freq[0]=1;
    int n=nums.size();
    int count=0;
    int i=0;
    while(i<n)
    {
        sum+=nums[i];
        int idx=sum%k;
        count+=freq[idx];
        freq[idx]++;
        i++;

    }       
    return count; 
}

int main()
{
    return 0;
}