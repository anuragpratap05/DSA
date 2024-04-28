#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
// class trp{
//     int r, c, steps;
//     trp(int r,int c,int steps)
//     {
//         this->r=r;
//         this->c=c;
//         this->steps=steps;
//     }
// };


int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n=maze.size();
    int m=maze[0].size();
    int r=max(n,m);
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int a=start[0];
    int b=start[1];
    int s_val=a*m+b;

    int x=destination[0];
    int y=destination[1];
    int d_val=x*m+y;
    

    pq.push({0,s_val});
    vis[a][b]=true;

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
            if(i==x and y==j)
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
                if(vis[r][c])
                {
                    continue;
                }
                vis[r][c]=true;
                pq.push({steps,r*m+c});
                
            }
            
        }


    }
    return -1;
}

int main()
{
    vector<vector<int>>maze ={{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int>start={0,4};
    vector<int>dest={4,4};

    cout<<shortestDistance(maze,start,dest);
    return 0;
}