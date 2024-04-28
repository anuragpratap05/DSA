#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> size;
int maxsize=1;
int find(int i)
{
    if(par[i]==i)
    {
        return i;
    }
    par[i]=find(par[i]);
    return par[i];
}

void unite(int p1,int p2)
{
    if(size[p1]<size[p2])
    {
        par[p1]=p2;
        size[p2]+=size[p1];
        maxsize=max(maxsize,size[p2]);
    }
    else{
        par[p2]=p1;
        size[p1]+=size[p2];
        maxsize=max(maxsize,size[p1]);
    }
}
void find_and_unite(int u,int v)
{
    int p1=find(u);
    int p2=find(v);
    if(p1!=p2)
    {
        unite(p1,p2);
    }
}
int maxAreaOfIsland_UF(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();

    par.resize(n*m);
    size.resize(n*m,1);
    for(int i=0;i<n*m;i++)
    {
        par[i]=i;
    }  
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                c++;
                int u=i*m+j;
                int v;
                if(j+1<m and grid[i][j+1]==1)
                {
                    v=i*m+(j+1);
                    find_and_unite(u,v);

                }
                if(i+1<n and grid[i+1][j]==1)
                {
                    v=(i+1)*m+j;
                    find_and_unite(u,v);
                }
            }
        }
    }  
    if(c==0) return 0;

    return maxsize;



}

int main()
{
    return 0;
}