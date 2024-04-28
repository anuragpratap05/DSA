#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> twosum(vector<int>& nums,int tar,int si,int ei)
{
    int n=nums.size();
    vector<vector<int>> ans;
    int c=0;
    while(si<ei)
    {
        if(nums[si]+nums[ei]==tar)
        {
            ans.push_back({nums[si],nums[ei]});
            si++;
            ei--;
            while( si<ei and nums[si]==nums[si-1])
            {
                si++;
            }
            while(si<ei and nums[ei]==nums[ei+1])
            {
                ei--;
            }
        }
        else if(nums[si]+nums[ei]<tar)
        {
            si++;
        }
        else{
            ei--;
        }


    }
    return ans;
}

void preapare(vector<vector<int>>& ans,vector<vector<int>>& sa,int mine)
{
    for(auto &vec:sa)
    {
        vector<int> ar;
        ar.push_back(mine);
        for(int ele:vec)
        {
            ar.push_back(ele);
        }
        ans.push_back(ar);
    }
}

vector<vector<int>> ksum(vector<int>& nums,int tar,int k,int si,int ei)
{
    if(k==2)
    {
        return twosum(nums,tar,si,ei);
    }
    //int n=nums.size();
    vector<vector<int>> ans;
    //int ei=n-1;
    for(int i=si;i<ei;)
    {
        vector<vector<int>> sa=ksum(nums,tar-nums[i],k-1,i+1,ei);
        preapare(ans,sa,nums[i]);
        i++;
        while(i<ei and nums[i]==nums[i-1])
        {
            i++;
        }
    }
    return ans;
    
}

int main()
{
    return 0;
}