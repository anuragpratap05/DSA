#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> twosum(vector<int>& nums,int si,int ei,int tar)
{
    int n=nums.size();
    vector<vector<int>> ans;
    
    while(si<ei)
    {
        int sum=nums[si]+nums[ei];
        if(sum==tar)
        {
            ans.push_back({nums[si],nums[ei]});
            si++;
            ei--;
            while(si<ei and nums[si-1]==nums[si])
            {
                si++;
            }

            while(ei>si and nums[ei+1]==nums[si])
            {
                ei--;
            }
        }
        else if(sum<tar)
        {
            si++;
        }
        else
        {
            ei--;
        }
    }
    return ans;
}
void prepareans(vector<vector<int>>& ans,vector<vector<int>>& sa,int fix)
{
    for(vector<int>& vec:sa)
    {
        vector<int>temp;
        temp.push_back(fix);
        for(int e:vec)
        {
            temp.push_back(e);
        }
        ans.push_back(temp);
    }
}
vector<vector<int>> threeSum(vector<int>& nums,int si,int ei,int tar)
{
    vector<vector<int>> ans;
    for(int i=si;i<ei;)
    {
        int fix=nums[i];
        vector<vector<int>> sa=twosum(nums,i+1,ei,tar-fix);
        prepareans(ans,sa,fix);
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