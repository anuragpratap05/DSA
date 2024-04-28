#include<bits/stdc++.h>
using namespace std;


int kadans_positive(vector<int>& nums)
{
    // this will give ans 0 if there are all neg nums
    int csum=0;
    int gsum=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int ele=nums[i];
        csum+=ele;
        if(csum>gsum)
        {
            gsum=csum;
        }
        if(csum<0)
        {
            csum=0;
        }
    }
    return gsum;
}

int kadan_pos_neg_both(vector<int>& nums)
{
    // this will give smallest neg. no. if all nums are neg.
    int gsum=INT_MIN;
    int csum=0;
    int n= nums.size();
    for(int i=0;i<n;i++)
    {
        int ele=nums[i];
        csum=max(csum+ele,ele);
        gsum=max(gsum,csum);

    }
    return gsum;
}

vector<int> kadans_pos_subarray(vector<int>& nums)
{
    // this will give ans 0 if there are all neg nums
    int csum=0;
    int gsum=0;
    int n=nums.size();
    int si=0;
    int ei=0;
    int csi=0;
    for(int i=0;i<n;i++)
    {
        int ele=nums[i];
        csum+=ele;
        if(csum>gsum)
        {
            si=csi;
            ei=i;
            gsum=csum;
        }
        if(csum<0)
        {
            csi=i+1;
            csum=0;
        }
    }
    return {gsum,si,ei};
}

int main()
{
    return 0;
}