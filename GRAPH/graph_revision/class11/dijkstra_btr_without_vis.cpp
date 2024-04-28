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
vector<int> dijkstra_btr_without_vis(vector<vector<edge>>& graph,int src)
{
    int n=graph.size();
    vector<int> dis(n,1e8);
    //vector<bool> vis(n,false);
    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int size=pq.size();
        while(size--)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            int wsf=p.first;
            int vtx=p.second;
            if(dis[vtx]<wsf)
            {
                continue;
            }
            
            dis[vtx]=wsf;// ye line likho chahe na
            for(edge e:graph[vtx])
            {
                if( wsf+e.w<dis[e.v])
                {
                    dis[e.v]=wsf+e.w;
                    pq.push({wsf+e.w,e.v});
                }
            }
        }
    }
    return dis;
}


int main()
{
    return 0;
}