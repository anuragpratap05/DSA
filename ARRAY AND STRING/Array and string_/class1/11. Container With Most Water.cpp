#include<bits/stdc++.h>
using namespace std;


int maxArea(vector<int>& height)
{
    int n=height.size();

    int i=0;
    int j=n-1;
    int maxi=-1;
    while(i<j)
    {
        int area=(j-i)*min(height[i],height[j]);
        maxi=max(maxi,area);
        if(height[i]<height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return maxi;
}

int main()
{
    return 0;
}