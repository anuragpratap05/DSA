#include<bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height)
{
    int n=height.size();
    int si=0;
    int ei=n-1;
    int maxi=0;

    while(si<ei)
    {
        int area=((ei-si)*(min(height[si],height[ei])));
        maxi=max(maxi,area);
        if(height[si]<height[ei])
        {
            si++;
        }
        else{
            ei--;
        }
    }      
    return maxi;  
}

int main()
{
    return 0;
}