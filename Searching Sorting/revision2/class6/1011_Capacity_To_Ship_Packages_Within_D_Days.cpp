#include<bits/stdc++.h>
using namespace std;

bool leja_skte(vector<int>& weights, int days,int ship_wt)
{
    int n=weights.size();
    int i=0;
    while(days--)
    {
        int mysum=0;
        while(mysum<=ship_wt and i<n)
        {
            mysum+=weights[i];
            i++;
        }
        if(mysum>ship_wt)
        {
            i--;
        }
        if(i==n)
        {
            //cout<<"ata";
            return true;
        }

    }
    return false;

}
int shipWithinDays(vector<int>& weights, int days)
{
    int n=weights.size();
    int si=INT_MAX, ei=0;

    for(int i=0;i<n;i++)
    {
        si=min(si,weights[i]);
        ei+=weights[i];
    }
    while(si<ei)
    {
        int mid=(si+ei)/2;
        if(leja_skte(weights,days,mid))
        {
            ei=mid;

        }
        else{
            si=mid+1;
        }
    }
    return si;


}

int main()
{
    vector<int>wt={1,2,3,4,5,6,7,8,9,10};
    int d=5;
    if(leja_skte(wt,5,14))
    {
        cout<<"le ja skte";
    }
    else{
        cout<<"nhi";
    }
    return 0;
}