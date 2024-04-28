#include<bits/stdc++.h>
using namespace std;

long long merge(vector<long long>& arr,long long l,long long r,long long mid)
{
    long long lsi=l;
    long long lei=mid;
    long long rsi=mid+1;
    long long rei=r;
    
    //long long j=mid+1;
    long long k=0;
    long long inversion=0;

    vector<long long> temp(r-l+1,0);

    while(lsi<=lei and rsi<=rei)
    {
        if(arr[lsi]>arr[rsi])
        {
            inversion+=(lei-lsi+1);
            temp[k++]=arr[rsi++];
            //swap(arr[i],arr[j]);
            //i++;
            
            
        }
        else{
            
            temp[k++]=arr[lsi++];

        }
    }

    while(lsi<=lei)
    {
        temp[k++]=arr[lsi++];
        
    }

    while(rsi<=rei)
    {
        temp[k++]=arr[rsi++];
        
    }

    k=0;

    for(long long i=l;i<=r;i++)
    {
        arr[i]=temp[k++];
    }
    return inversion;
}


long long mergesort(vector<long long>& arr,long long si,long long ei)
{
    if(si>=ei )
    {
        return 0;
    }
    long long mid=(si+ei)/2;
    

    long long l=mergesort(arr,si,mid);
    long long r=mergesort(arr,mid+1,ei);

   
    return (l+r+merge(arr,si,ei,mid));
}

int main()
{
    vector<long long> vec={10,10,10};
    cout<<mergesort(vec,0,vec.size()-1)<<endl;
    for(int ele:vec)
    {
        cout<<ele<<" ";
    }
    return 0;
}