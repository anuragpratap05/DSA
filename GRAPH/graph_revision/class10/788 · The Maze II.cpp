#include<bits/stdc++.h>
using namespace std;


int hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        int n=maze.size();
    int m=maze[0].size();
    int r=max(n,m);
    vector<vector<int>> dis(n,vector<int>(m,1e8));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int a=start[0];
    int b=start[1];
    int s_val=a*m+b;

    int x=destination[0];
    int y=destination[1];
    int d_val=x*m+y;
    

    pq.push({0,s_val});
    dis[a][b]=0;

    while(!pq.empty())
    {
        int size=pq.size();
        while(size--)
        {
            pair<int,int> p =pq.top();
            pq.pop();
            int idx=p.second;
            
            //cout<<"steps="<<steps<<" "<<"idx="<<idx<<endl;
            int i=idx/m;
            int j=idx%m;
                if(i==x and j==y)
            {
                return p.first;
            }
            for(auto d:dir)
            {   
                int steps=p.first;
                int r=i;
                int c=j;
                while(r>=0 and c>=0 and r<n and c<m and maze[r][c]==0)
                {
                    r+=d[0];
                    c+=d[1];
                    steps++;
                }
                r-=d[0];
                c-=d[1];
                steps--;
                if(steps>= dis[r][c])
                {
                    continue;
                }
                dis[r][c]=steps;
                pq.push({steps,r*m+c});
            
                
            }
            
        }


    }
    return -1;
}

int main()
{
    vector<int>start={0,4};
    vector<int>end={3,2};
    vector<vector<int>>maze={{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    hasPath(maze,start,end);
    return 0;
}