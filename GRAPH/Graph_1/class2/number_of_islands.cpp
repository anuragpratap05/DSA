#include<bits/stdc++.h>
using namespace std;

void help(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& vis,int n,int m)
{
    if( i==n or i<0 or j==m or j<0 or  grid[i][j]=='0' or vis[i][j]==true)
    {
        return;
    }

    vis[i][j]=true;
    help(grid,i,j+1,vis,n,m);
    help(grid,i+1,j,vis,n,m);
    help(grid,i,j-1,vis,n,m);
    help(grid,i-1,j,vis ,n,m);
}

int numIslands(vector<vector<char>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    //cout<<n<<"  "<<m<<endl;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    
    int compo=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] and grid[i][j]=='1')
            {
                compo++;
                help(grid,i,j,vis,n,m);
            }
        }
    }  
    return compo;   
}
//method2

void help2(vector<vector<char>>& grid,int i, int j,vector<vector<int>>& dir,int n,int m)
{
    for(int d=0;d<dir.size();d++)
    {
        int r=i+dir[d][0];
        int c=j+dir[d][1];
        if(r>=0 and c>=0 and r<n and c<m and grid[r][c]=='1')
        {
            grid[r][c]='0';
            help2(grid,r,c,dir,n,m);
        }
    }
}

int numIslands2(vector<vector<char>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    
    
    int compo=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(grid[i][j]=='1')
           {
               compo++;
               help2(grid,i,j,dir,n,m);
           }
        }
    }  
    return compo;   
}

int main()
{


    vector<vector<char>> grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
    };
   cout<< numIslands2(grid);
return 0;
}