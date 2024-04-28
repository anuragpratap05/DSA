#include<bits/stdc++.h>
using namespace std;
int help2(vector<vector<int>>& grid,int i, int j,vector<vector<int>>& dir,int n,int m)
{
   grid[i][j]=0;
    int area=0;
    for(int d=0;d<dir.size();d++)
    {
        int r=i+dir[d][0];
        int c=j+dir[d][1];
        if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
        {
            
           area+= help2(grid,r,c,dir,n,m);
        }
    }
    return area+1;
}


int islandPerimeter(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    
    int onec=0;
    int nc=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(grid[i][j]==1)
           {
               onec++;
               
                 for(int d=0;d<dir.size();d++)
                {
                    int r=i+dir[d][0];
                    int c=j+dir[d][1];
                    if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
                    {
                        
                        if(grid[r][c]==1)
                        {
                            nc+=1;
                        }
                    }
                }
           }
        }
    }  
    int ans=4*onec-nc;
    return  ans;
}

int main()
{
    return 0;
}