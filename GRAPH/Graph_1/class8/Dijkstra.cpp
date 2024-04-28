#include<bits/stdc++.h>
using namespace std;
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
    priority_queue<pair_> pq;
    vector<bool> vis(V,false);
    vector<vector<edge>> mygraph(V,vector<edge>());
    pq.push(pair_(src,-1,0,0));

    while(!pq.empty())
    {
        pair_ p=pq.top();
        pq.pop();
        if(vis[p.src])
        {
            continue;
        }

        // this is only for contructing graph if u want
        if(p.par!=-1)
        {
            addedge(mygraph,p.src,p.par,p.wt);
        }

        vis[p.src]=true;

        for(edge e:graph[p.src])
        {
            if(!vis[e.v])
            {
                pq.push(pair_(e.v,p.src,p.wsf+e.w,e.w));
            }
        }
    }

}

int main()
{
    return 0;
}