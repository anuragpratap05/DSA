#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
void dfs(vector<vector<char>>& grid,int i,int j,int n,int m)
{
    grid[i][j]='P';
    for(auto vec:dir)
    {
        int r=i+vec[0];
        int c=j+vec[1];
        if(r>=0 and c>=0 and r<n and c<m and grid[r][c]=='O')
        {
            
            dfs(grid,r,c,n,m);
        }
    }
}
void solve(vector<vector<char>>& board)
{
    int n=board.size();
    int m=board[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i==0 or j==0 or i==n-1 or j==m-1)and board[i][j]=='O')
            {
                dfs(board,i,j,n,m);
            }
        }
    } 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='P')
            {
                board[i][j]='O';
            }
            else{
                board[i][j]='X';
            }
        }
    }   
    //return board;    
}

int main()
{
    return 0;
}