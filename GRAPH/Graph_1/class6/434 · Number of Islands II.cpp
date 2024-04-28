#include<bits/stdc++.h>
using namespace std;

 struct Point {
     int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
      int find(int u)
{
    if(par[u]==u)
    {
        return u;

    }
    par[u]=find(par[u]);
    return par[u];
}
  vector<int> par;
vector<int> numIslands2(int n, int m, vector<Point> &operators)
{
    vector<vector<int>> vis(n,vector<int>(m,0));
    par.resize(n*m);
    for(int i=0;i<n*m;i++)
    {
        par[i]=i;
    }
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    vector<int> vec;

    int count=0;
    for(int i=0;i<operators.size();i++)
    {
        
        
        int sr=operators[i].x;
        int sc=operators[i].y;
        if(vis[sr][sc]==1)
        {
            vec.push_back(count);
            continue;
        }
        vis[sr][sc]=1;
        count++;

        int v=sr*m+sc;
        int p1=find(v);

        for(vector<int>& d:dir)
        {
            int r=sr+d[0];
            int c=sc+d[1];
            if( r>=0 and c>=0 and r<n and c<m and   vis[r][c]==1)
            {
                int p2=find(r*m+c);
                if(p1!=p2)
                {
                    par[p2]=p1;
                    count--;
                }
            }
        }
        vec.push_back(count);
    }
   


    
}

int main()
{
    return 0;
}