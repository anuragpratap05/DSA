#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> twosum(vector<int>& nums,int tar,int si,int ei)
{
    int n=nums.size();
    vector<vector<int>> ans;
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

vector<vector<int>> threesum(vector<int> nums,int tar,int si,int ei)
{
    int n=nums.size();
    vector<vector<int>> ans;
    for(int i=si;i<ei;)
    {
        vector<vector<int>> sa=twosum(nums,tar-nums[i],i+1,ei);
        preapare(ans,sa,nums[i]);
        i++;
        while(i<ei and nums[i]==nums[i-1])
        {
            i++;
        }
    }
    return ans;

}
vector<vector<int>> fourSum(vector<int>& nums, int tar)
{
    int n=nums.size();
    vector<vector<int>> ans;
    int ei=n-1;
    for(int i=0;i<n-1;)
    {
        vector<vector<int>> sa=threesum(nums,tar-nums[i],i+1,ei);
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
   // vector<int> vec={-1,-1,-1,-1,-1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4,6,6,6,6,6};
   vector<int> vec={-2,0,1,1,2};
    int tar=2;
    int n=vec.size();
   vector<vector<int>> ans= twosum(vec,tar,0,n-1);
   for(auto &vec:ans)
   {
       for(int e:vec)
       {
           cout<<e<<",";
       }
       cout<<endl;
   }


    return 0;
}