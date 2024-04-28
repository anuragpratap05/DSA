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

int main()
{

    vector<int>vec={0,0,0,0};
    sort(vec.begin(),vec.end());
    vector<vector<int>>ans=twosum(vec,0,3,0);
    for(vector<int>& v:ans)
    {
        for(int e:v)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}