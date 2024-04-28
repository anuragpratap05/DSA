#include<bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n=matrix.size();        
    int m=matrix[0].size();

    int r=n-1;
    int c=0;

    while(c<m and r>=0)
    {
        if(target==matrix[r][c])
        {
            return true;
        }
        else if(target<matrix[r][c])
        {
            r--;
        }
        else
        {
            c++;
        }
    }
    return false;
}

int main()
{
    return 0;
}