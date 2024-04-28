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
    graph[v].push_back({u,w});
}
struct comp{
    bool operator()(vector<int>& a,vector<int>& b)
    {
        return a[2]>b[2];
    }
};
void prims(vector<vector<edge>>& graph,int src,vector<bool>& vis)
{
    priority_queue<vector<int>,vector<vector<int>>,comp> pq;
    pq.push({0,-1,0,0});
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
        vis[vtx]=true;
        cout<<par<<"-->"<<vtx<<","<<wt<<endl;
        //cout<<vtx<<"-->"<<wsf<<endl;
        for(edge e:graph[vtx])
        {
            if(!vis[e.v])
            {
                pq.push({e.v,vtx,e.w,wsf+e.w});
            }
        }

    }
    
}

int main()
{
    int V=9;
    vector<vector<edge>>graph(V,vector<edge>());
    vector<bool> vis(V,false);
    addedge(graph,0,1,4);
    addedge(graph,0,7,8);

    addedge(graph,1,7,11);

    addedge(graph,1,2,8);
    addedge(graph,7,6,1);
    addedge(graph,7,8,7);

    addedge(graph,2,8,2);

    addedge(graph,8,6,6);

    addedge(graph,2,3,7);
    addedge(graph,2,5,4);

    addedge(graph,6,5,2);
    addedge(graph,3,5,14);

    addedge(graph,3,4,9);

    addedge(graph,5,4,10);
    prims(graph,0,vis);
    return 0;
}