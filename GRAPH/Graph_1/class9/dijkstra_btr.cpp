#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<edge>>& graph,int u,int v,int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));


    
}

void addedge(vector<vector<edge>>& graph,int u,int v,int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));


    
}

class edge
{
    public:
    int v,w;
    edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};
class pair_
{
    public:
    int src,par,wsf,wt;
    pair_(int src,int par,int wsf,int wt)
    {
        this->src=src;
        this->par=par;
        this->wsf=wsf;
        this->wt=wt;
    }
};

void dijksta(vector<vector<edge>>& graph,int V,int src)
{
    vector<bool> vis(V,false);
    vector<int> dis(V,INT_MAX);
    vector<int> par(V,-1);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        pair <int,int> p=pq.top();
        pq.pop();
        int wsf=p.first;
        int nsrc=p.second;

        if(vis[nsrc])
        {
            continue;
        }
        vis[nsrc]=true;
        //dis[nsrc]=wsf;
        for(edge e:graph[nsrc])
        {
            int dest=e.v;
            int cur_wt=e.w;
            if(!vis[dest] and wsf+cur_wt< dis[dest])
            {
                dis[dest]=wsf+cur_wt;
                par[dest]=nsrc;
                pq.push({wsf+cur_wt,dest});
            }
        }

    }
}

int main()
{
    return 0;
}