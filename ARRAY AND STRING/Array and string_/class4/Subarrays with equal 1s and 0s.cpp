#include<bits/stdc++.h>
using namespace std;


long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                arr[i]=-1;
            }
        }
        map<int,int> m;
        m[0]=1;
        int ei=0;
        int sum=0;
        int ans=0;
        
        while(ei<n)
        {
            sum+=arr[ei];
            if(m.find(sum)==m.end())
            {
                m[sum]=1;
            }
            else
            {
                ans+=m[sum];
                m[sum]++;
            }
            ei++;
        }
        return ans;
    }

int main()
{
    return 0;
}