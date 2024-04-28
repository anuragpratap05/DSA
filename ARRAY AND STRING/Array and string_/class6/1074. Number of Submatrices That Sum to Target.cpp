#include<bits/stdc++.h>
using namespace std;
int count_of_subarrays_equalto_target(vector<int>& arr,int tar)
{
    map<int,int> m;
    m[0]=1;
    int sum=0,c=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
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
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> sum(m,0);
    int c=0;
    for(int r=0;r<n;r++)
    {
        sum.clear();
        sum.resize(m,0);
        for(int i=r;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum[j]+=matrix[i][j];
            }
             c+=count_of_subarrays_equalto_target(sum,target);
        }
    }   
    return c;     
}

int main()
{
    return 0;
}