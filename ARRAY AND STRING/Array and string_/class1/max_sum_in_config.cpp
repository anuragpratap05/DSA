#include<bits/stdc++.h>
using namespace std;


int max_sum(int A[],int N)
{
    int sum=0;
    for(int i=0;i<N;i++)
    {
       sum+=A[i]; 
    }
   // cout<<"sum="<<sum<<endl;
    int val=0;
    
    for(int i=0;i<N;i++)
    {
        val+= i*A[i];
    }
    int maxi=val;
    //cout<<val<<endl;
    for(int i=1;i<N;i++)
    {
        val= val-sum+(N*A[i-1]);
       // cout<<val<<" ";
        maxi=max(maxi,val);
    }
    return maxi;

}

int main()
{
    return 0;
}