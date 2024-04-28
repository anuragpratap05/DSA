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
        if(m.find(sum)!=m.end())
        {
            m[sum]++;
        }
        else
        {
            m[sum]=1;
        }
    }
    return c;
}

int main()
{
    vector<int>x={1,1,0,2,2};
    int tar=4;
    cout<<count_of_subarrays_equalto_target(x,tar);
    return 0;
}