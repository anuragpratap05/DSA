#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
int islandPerimeter(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                int area=4;
                for(auto vec:dir)
                {
                    int r=i+vec[0];
                    int c=j+vec[1];
                    if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
                    {
                        area--;
                    }
                }
                sum+=area;
            }
        }
    } 
    return sum; 
}

int main()
{
    return 0;
}