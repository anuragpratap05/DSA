#include<bits/stdc++.h>
using namespace std;


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,1},{1,-1},{-1,-1}};
    if(grid[0][0]==1 or grid[n-1][m-1]==1)
    {
        return -1;
    }
        if(n==1 and m==1 and grid[0][0]==0)
        {
            return 1;
        }
    
    queue<int>q;
    q.push(0);
    grid[0][0]=1;
    int shortest=1;

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int idx=q.front();
            q.pop();
            int sr=idx/m;
            int sc=idx%m;
            for(int d=0;d<dir.size();d++)
            {
                int r=sr+dir[d][0];
                int c=sc+dir[d][1];
                if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==0)
                {
                    grid[r][c]=1;
                    q.push(r*m+c);
                    if(r==n-1 and c==m-1)
                    {
                        return shortest+1;
                    }
                }
            }
        }
        shortest++;
    }
    return -1;
    }

int main()
{
    return 0;
}