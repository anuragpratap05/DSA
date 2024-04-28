#include<bits/stdc++.h>
using namespace std;


int kadanes(vector<int> arr)
{
    int n=arr.size();
    int csum=0;
    int gsum=0;
    for(int i=0;i<n;i++)
    {
        int ele=arr[i];
        csum+=ele;
        if(csum<=0)
        {
            csum=0;
        }
        if(csum>gsum)
        {
            gsum=csum;
        }


    }
    return gsum;
}

int kadanegeneric(vector<int> arr)
{
    int n=arr.size();
    int csum=0;
    int gsum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int ele=arr[i];
        csum=max(ele,csum+ele);
        gsum=max(gsum,csum);
    }
    return gsum;
}

int main()
{
    return 0;
}