#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n=maze.size();
    int m=maze[0].size();
    int r=max(n,m);
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<int> q;
    int a=start[0];
    int b=start[1];
    int s_val=a*m+b;

    int x=destination[0];
    int y=destination[1];
    int d_val=x*m+y;
    

    q.push(s_val);

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int idx=q.front();
            q.pop();

            int i=idx/m;
            int j=idx%m;
            for(auto d:dir)
            {
                int r=i;
                int c=j;
                while(r>=0 and c>=0 and r<n and c<m and maze[r][c]==0)
                {
                    r+=d[0];
                    c+=d[1];
                }
                r-=d[0];
                c-=d[1];
                if(vis[r][c])
                {
                    continue;
                }
                cout<<r<<" "<<c<<endl;
                vis[r][c]=true;
                q.push(r*m+c);
                // if(r==x and c==y)
                // {
                //     return true;
                // }
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