#include<bits/stdc++.h>
using namespace std;

vector<int >par,size;
int find(int u)
{
    if(par[u]==u)
    {
        return u;

    }
    par[u]=find(par[u]);
    return par[u];
}
void Union(int p1,int p2)
{
    if(size[p1]<size[p2])
    {
        par[p1]=p2;
        size[p2]+=size[p1];
    }
    else
    {
        par[p2]=p1;
        size[p1]+=size[p2];
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    int val=n*m+m;
    par.resize(val);
    size.resize(val);

    for(int i=0;i<val;i++)
    {
        par[i]=i;
        size[i]=1;
    }
    vector<vector<int>>edges;
    vector<vector<int>> dir={{1,0},{0,1}};
    int one=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                one++;
                for(int d=0;d<dir.size();d++)
                {
                    int r=i+dir[d][0];
                    int c=j+dir[d][1];

                    if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
                    {
                        edges.push_back({i*m+j,r*m+c});
                    }
                }
                grid[i][j]=0;
            }
            
        }
    }

    for(vector<int>& vec:edges)
    {
        int u=vec[0];
        int v=vec[1];

        int p1=find(u);
        int p2=find(v);
        if(p1!=p2)
        {
            Union(p1,p2);
        }
    }
    int maxi=-1;
    for(int e:size)
    {
        maxi=max(maxi,e);
    }


}


//method 2 using DSU
class Solution {
public:
    vector<int> par,size;
    int find(int u)
{
    if(par[u]==u)
    {
        return u;

    }
    par[u]=find(par[u]);
    return par[u];
}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        par.resize(n*m);
        size.resize(n*m);
        
        for(int i=0;i<n*m;i++)
        {
            par[i]=i;
            size[i]=1;
        }
        vector<vector<int>> dir={{1,0},{0,1}};
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int p1=find(i*m+j);
                    
                for(int d=0;d<dir.size();d++)
                {
                    int r=i+dir[d][0];
                    int c=j+dir[d][1];

                    if(r>=0 and c>=0 and r<n and c<m and grid[r][c]==1)
                    {
                        int p2=find(r*m+c);
                        if(p1!=p2)
                        {
                             par[p2]=p1;
                        size[p1]+=size[p2];
                        }
                       
                    }
                }
                grid[i][j]=0;
                maxi=max(maxi,size[p1]);
                }
            }
        }
        return maxi;
        
    }
};

int main()
{
    return 0;
}