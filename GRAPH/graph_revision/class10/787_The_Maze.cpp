#include<bits/stdc++.h>
using namespace std;


bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    int n=maze.size();
    int m=maze[0].size();
    int i=start[0];
    int j=start[1];
    int fr=destination[0];
    int fc=destination[1];
    queue<int>q;
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    q.push(i*m+j);
    vis[i][j]=true;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int idx=q.front();
            q.pop();
            i=idx/m;
            j=idx%m;
            for(vector<int>& vec:dir)
            {
                
                int r=i;
                int c=j;
                while(r>=0 and c>=0 and r<n and c<m  and maze[r][c]==0)
                {
                    r+=vec[0];
                    c+=vec[1];
                }
                r-=vec[0];
                c-=vec[1];
                if(vis[r][c]==true)
                {
                    continue;
                }
                
                
                    if(r==fr and c==fc)
                    {
                        return true;
                    }
                    //cout<<r<<" "<<c<<endl;
                    vis[r][c]=true;
                    q.push(r*m+c);
                


            }
        }
    }
    return false;
}

int main()
{
    vector<int>start={0,4};
    vector<int>end={3,2};
    vector<vector<int>>maze={{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    hasPath(maze,start,end);
    return 0;
}