#include<bits/stdc++.h>
using namespace std;



void surround(vector<vector<char>>& board,int i,int j,vector<vector<int>>& dir)
{
    board[i][j]='$';
     int n=board.size();
    int m=board[0].size();
    for(int d=0;d<dir.size();d++)
    {
        int r=i+dir[d][0];
        int c=j+dir[d][1];
        if(r>=0 and c>=0 and r<n and c<m and  board[r][c]=='O')
        {
            surround(board,r,c,dir);
        }
    }
}


void solve(vector<vector<char>>& board)
{
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 or j==0 or i==n-1 or j==m-1)
            {
                if(board[i][j]=='O')
                {
                    surround(board,i,j,dir);
                }
            }
        }
    }  

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='$')
            {
                board[i][j]='O';
            }
            else if(board[i][j]=='O')
            {
                board[i][j]='X';
            }
        }
    }      
}

int main()
{
    return 0;
}