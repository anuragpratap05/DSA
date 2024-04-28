#include<bits/stdc++.h>
using namespace std;

bool kha_skte_h(vector<int>& piles, int h,int eating_speed)
{
    int my_h=0;
    for(int i=0;i<piles.size();i++)
    {
        my_h+= ceil(piles[i]/(eating_speed*1.0));
        if(my_h>h)
        {
            return false;
        }
    }
    return true;
}


int minEatingSpeed(vector<int>& piles, int h)
{
    int si=1;
    int ei=1e9;

    while(si<ei)
    {
        int eating_speed=(si+ei)/2;
        if(kha_skte_h(piles,h,eating_speed))
        {
            ei=eating_speed;
        }
        else
        {
            si=eating_speed+1;
        }
    }
    return si;

}

int main()
{
    return 0;
}