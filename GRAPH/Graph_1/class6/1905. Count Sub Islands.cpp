#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,int n,int m,vector<bool>& flag)
{
    if(grid1[i][j]!=1)
    {
        flag[0]=false;
    }
    grid2[i][j]=0;
    for(vector<int>& d:dir)
    {
        int r=i+d[0];
        int c=j+d[1];

        if(r>=0 and c>=0 and r<n and c<m and grid2[r][c]==1)
        {
            dfs(grid1,grid2,r,c,n,m,flag);
        }
    }


}
//method 2 using return type
bool dfs2(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,int n,int m,vector<bool>& flag)
{
    
    grid2[i][j]=0;
    bool res=true;
    for(vector<int>& d:dir)
    {
        int r=i+d[0];
        int c=j+d[1];

        if(r>=0 and c>=0 and r<n and c<m and grid2[r][c]==1)
        {
           res= dfs2(grid1,grid2,r,c,n,m,flag) and res;
        }
    }
    return res and (grid1[1][j]==1);

}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
{
    int n=grid1.size();
    int m=grid1[0].size();
    vector<bool> flag(1,true);

   // vector<vector<bool>> vis(n,vector<bool>(m,false));
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid1[i][j]==1 and grid2[i][j]==1 )
            {
                
                dfs(grid1,grid2,i,j,n,m,flag);
                if(flag[0]==false)
                {
                    flag[0]=true;
                }
                else{
                    c++;
                }
            }
        }
    }  
    return c;      
}

int main()
{
    return 0;
}