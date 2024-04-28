#include<bits/stdc++.h>
using namespace std;
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
void addedge(vector<vector<edge>>& graph,int u,int v,int w)
{
    graph[u].push_back({v,w});
    //graph[v].push_back({u,w});
}
struct comp{
    bool operator()(vector<int>& a,vector<int>& b)
    {
        return a[3]>b[3];
    }
};
int dijkstra(vector<vector<edge>>& graph,int src,vector<bool>& vis)
{
    priority_queue<vector<int>,vector<vector<int>>,comp> pq;
    pq.push({src,-1,0,0});
    int ans=0;
    
    while(!pq.empty())
    {
        vector<int> node=pq.top();
        pq.pop();
        int vtx=node[0];
        int par=node[1];
        int wt=node[2];
        int wsf=node[3];

        if(vis[vtx])
        {
            continue;
        }
        ans=max(ans,wsf);
        vis[vtx]=true;
        //cout<<vtx<<"-->"<<wsf<<endl;
        for(edge e:graph[vtx])
        {
            if(!vis[e.v])
            {
                pq.push({e.v,vtx,e.w,wsf+e.w});
            }
        }

    }
    return ans;
    
}

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    int V=n+1;
    vector<vector<edge>>graph(V,vector<edge>());
    vector<bool> vis(V,false);
    for(vector<int>& vec:times)
    {
        int u=vec[0];
        int v=vec[1];
        int w=vec[2];

        addedge(graph,u,v,w);
    }
    int ans= dijkstra(graph,k,vis);
    for(int i=1;i<V;i++)
    {
        if(!vis[i])
        {
            return -1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}