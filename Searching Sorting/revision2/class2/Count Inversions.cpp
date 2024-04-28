#include<bits/stdc++.h>
using namespace std;




long long merge(vector<long long>& nums,long long si,long long ei,vector<long long>&temp)
{
    long long mid=(si+ei)/2;
    
    long long i=si;
    long long j=mid+1;
    long long k=0;
    long long c=0;
    while(i<=mid and j<=ei)
    {
        if(nums[i]<=nums[j])
        {
            temp[k]=nums[i];
            i++;
            k++;
        }
        else{
            c+=(mid-i)+1;
            temp[k]=nums[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        temp[k]=nums[i];
            i++;
            k++;
    }

    while(j<=ei)
    {
        temp[k]=nums[j];
            j++;
            k++;
    }
    k=0;
    for(long long i=si;i<=ei;i++)
    {
        nums[i]=temp[k];
        k++;
    }
    return c;
}

long long merge_sort(vector<long long>& nums,long long si,long long ei,vector<long long>&temp)
{
    if(si>=ei)
    {
        return 0;
    }
    long long mid=(si+ei)/2;
    long long lc=merge_sort(nums,si,mid,temp);
    long long rc=merge_sort(nums,mid+1,ei,temp);
    long long mc=merge(nums,si,ei,temp);
    return (lc+rc+mc);
}

long long main()
{
    return 0;
}


