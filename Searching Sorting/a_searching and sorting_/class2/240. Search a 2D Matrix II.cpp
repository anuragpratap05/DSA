#include<bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int r=n-1;
    int c=0;

    while(r>=0 and c<m)
    {
        if(matrix[r][c]==target)
        {
            return true;
        }
        else if(matrix[r][c]<target)
        {
            c++;
        }
        else{
            r--;
        }
    }
    return false;


}

int main()
{
    return 0;
}