#include<bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    queue<int>q;
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

    int fresh=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push(i*m+j);
            }
            else if(grid[i][j]==1)
            {
                fresh++;
            }
        }
    }
    int time=0;
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
                if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
                {
                    grid[r][c]=2;
                    q.push(r*m+c);
                    fresh--;
                    if(fresh==0)
                    {
                        return time+1;
                    }

                }
            }
        }
        time++;
    }

    return -1;
}

int main()
{
    return 0;
}