#include<bits/stdc++.h>
using namespace std;


 vector<int>par;
vector<int>size;
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
    }
    else{
        par[p2]=p1;
        size[p1]+=size[p2];
    }
}

vector<int> unionfind(vector<vector<int>>& edges)
{
    int n=edges.size();
    par.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int p1=find(u);
        int p2=find(v);
        if(p1!=p2)
        {
            unite(p1,p2);
        }
        else
        {
            return {u,v};
        }
    }
    return {0,0};
}

int main()
{
    return 0;
}