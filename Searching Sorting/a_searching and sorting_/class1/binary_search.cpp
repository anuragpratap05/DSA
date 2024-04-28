#include<bits/stdc++.h>
using namespace std;


int binary_search(vector<int>& arr,int tar)
{
    int n=arr.size();
    int ei=n-1,si=0;
    while(si<=ei)
    {
        int mid=(si+ei)/2;
        if(tar==arr[mid])
        {
            return mid;
        }
        if(arr[mid]<tar)
        {
            si=mid+1;
        }
        else{
            ei=mid-1;
        }
    }
    return -1;
}

int main()
{
    return 0;
}