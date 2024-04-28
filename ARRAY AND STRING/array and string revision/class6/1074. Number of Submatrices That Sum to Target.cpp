#include<bits/stdc++.h>
using namespace std;

int help(vector<int>& nums,int tar)
{
    map<int,int> m;
    int n=nums.size();
    int sum=0;
    int c=0;
    m[0]=1;
    for(int ele:nums)
    {
        sum+=ele;
        if(m.find(sum-tar)!=m.end())
        {
            c+=m[sum-tar];
        }
        m[sum]++;
    }
    return c;
}


int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
{
    int R=matrix.size();
    int C=matrix[0].size();
    vector<int>vec(C,0);
    int c=0;
    for(int r=0;r<R;r++)
    {
        vec.clear();
        vec.resize(C,0);
        for(int i=r;i<R;i++)
        {
            
            for(int j=0;j<C;j++)
            {
                
                vec[j]+=matrix[i][j];
            }
            c+=help(vec,target);
        }
    }  
    return c;      
}

int main()
{
    return 0;
}