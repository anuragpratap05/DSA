#include<bits/stdc++.h>
using namespace std;


bool leja_skte(vector<int>& weights, int days,int cap)
{
    int n=weights.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        // if(i==n-1)
        // {
        //     days--;
        // }
        
        sum+=weights[i];
        if(sum>cap)
        {
            days--;
            sum=0;
            i--;
        }
        if(days<0 or (days==0 and i<n))
        {
            return false;
        }
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days)
{
    int si=1;
    int ei=1e9;
    while(si<ei)
    {
        int cap=(si+ei)/2;
        if(leja_skte(weights,days,cap))
        {
            ei=cap;
        }
        else
        {
            si=cap+1;
        }
    }
    return si;

}

int main()
{
    return 0;
}