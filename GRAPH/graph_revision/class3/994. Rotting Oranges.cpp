#include<bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();

    queue<int >q;
    int fresh=0;
    //vector<bool> vis(n*m,false);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push(i*m+j);
                grid[i][j]=0;
            }
            else if(grid[i][j]==1)
            {
                fresh++;
            }
        }
    }  
    if(fresh==0)
    {
        return 0;
    } 
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    int level=0;
    
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int idx=q.front();
            q.pop();
            int i=idx/m;
            int j=idx%m;
            for(auto vec:dir)
            {
                int r=i+vec[0];
                int c=j+vec[1];
                if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
                {
                    q.push(r*m+c);
                    grid[r][c]=0;
                    fresh--;
                    if(fresh==0)
                    {
                        return level+1;
                    }
                }
            }
        }
        level++;

    }  
    return -1;  
}

int main()
{
    return 0;
}