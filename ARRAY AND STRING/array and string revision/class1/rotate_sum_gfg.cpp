#include<bits/stdc++.h>
using namespace std;


int max_sum(int A[],int N)
{
//Your code here
    int array_sum=0;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        array_sum+=A[i];
        sum+=(i*A[i]);
    }
    //int sum=0;
    int maxi=sum;
    for(int i=0;i<N-1;i++)
    {
        sum=sum-(array_sum-A[i])+A[i]*(N-1);
        maxi=max(sum,maxi);
    }
    return maxi;
    
}

int main()
{
    return 0;
}