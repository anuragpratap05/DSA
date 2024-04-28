#include<bits/stdc++.h>
using namespace std;

bool kha_skte_h(vector<int>& piles, int h,int speed)
{
    int total_hrs=0;
    for(int e:piles)
    {
        int val=e/speed;
        if(e%speed!=0)
        {
            val++;
        }
        total_hrs+=val;
        if(total_hrs>h)
        {
            return false;
        }
    }
    return true;
}


int minEatingSpeed(vector<int>& piles, int h)
{
    int si=1;
    int ei=1e8;
    while(si<ei)
    {
        int mid=(si+ei)/2;
        if(kha_skte_h(piles,h,mid))
        {
            ei=mid;
        }
        else
        {
            si=mid+1;
        }
    }
    return si;
}

int main()
{
    return 0;
}