#include<bits/stdc++.h>
using namespace std;


int numcounts;
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
void dfs(vector<vector<int>>& grid,int i,int j,int n,int m)
{
    
    for(auto vec:dir)
    {
        int r=i+vec[0];
        int c=j+vec[1];
        if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
        {
            numcounts+=1;
            grid[r][c]=0;
            dfs(grid,r,c,n,m);
        }
    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
             int n=grid.size();
        int maxi=0;
    int m=grid[0].size();
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                numcounts=1;
                grid[i][j]=0;
                dfs(grid,i,j,n,m);
                //if(numcounts!=0)numcounts+=1;
                maxi=max(maxi,numcounts);
            }
        }
    }
    return maxi;
    }

int main()
{
    return 0;
}