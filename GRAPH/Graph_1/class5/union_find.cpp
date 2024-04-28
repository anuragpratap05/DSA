#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int v;
    int w;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addedge(vector<vector<Edge>>& graph,int u,int v,int w)
{
    graph[u].push_back(Edge(v,w));
    graph[v].push_back(Edge(u,w));

}

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

void union_find(vector<vector<int>> edges,int n)
{
    
    vector<vector<Edge>> graph(n,vector<Edge>());
    par.resize(n);
    size.resize(n);
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        size[i]=1;
    }
    
    for(vector<int>& vec:edges)
    {
        int u=vec[0];
        int v=vec[1];
        int w=vec[2];

        int p1=find(u);
        int p2=find(v);

        if(p1!=p2)
        {
            Union(p1,p2);
            addedge(graph,u,v,w);
        }    
    }
}

int main()
{
    return 0;
}