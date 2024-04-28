#include<bits/stdc++.h>
using namespace std;


int kadans(vector<int>& nums)
{
    int n = nums.size();
    int csum = 0, gsum = 0;

    for(int ele:nums)
    {
        csum += ele;
        gsum = max(gsum, csum);
        if(csum<0)
        {
            csum = 0;
        }
    }
    return gsum;
}

long long maxSubarraySum(int arr[], int n)
{
    long long csum = 0;
    long long gsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        long long ele = arr[i];
        csum = max(ele, csum + ele);
        gsum = max(csum, gsum);
    }
    return gsum;
}

int main()
{
    return 0;
}