#include<bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int si=0;
    int ei=n*m-1;

    while(si<=ei)
    {
        int mid=(ei+si)/2;
        int r=mid/m;
        int c=mid%m;
        if(matrix[r][c]==target)
        {
            return true;
        }
        if(matrix[r][c]<target)
        {
            si=mid+1;
        }
        else
        {
            ei=mid-1;
        }
    }
    return false;
}

int main()
{
    return 0;
}