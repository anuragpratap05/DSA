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

vector<int> dijkstra_btr(vector<vector<edge>>& graph,int src)
{
    int n=graph.size();
    vector<int> dis(n,1e8);
    vector<bool> vis(n,false);
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
            if(vis[vtx])
            {
                continue;
            }
            
            vis[vtx]=true;
            for(edge e:graph[vtx])
            {
                if(!vis[e.v] and wsf+e.w<dis[e.v])
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
    int n,m,k,x;
    
    cin>>n>>m>>k>>x;
    vector<vector<edge>> graph(n+1,vector<edge>());
    vector<int>chocolates;
    for(int i=0;i<k;i++)
    {
        int ele;
        cin>>ele;
        chocolates.push_back(ele);
    }
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        
        cin>>u>>v>>w;
        addedge(graph,u,v,w);
    }
    int src,dst;
    cin>>src>>dst;

    vector<int> vec1=dijkstra_btr(graph,src);
    vector<int> vec2=dijkstra_btr(graph,dst);
    int ans=1e8;
    for(int i=0;i<chocolates.size();i++)
    {
        int idx=chocolates[i];
        if(vec1[idx]!=1e8 and vec2[idx]<x)
        {
            ans=min(ans,vec1[idx]+vec2[idx]);
        }
        

    }
    if(ans==1e8)
    {
        cout<<"-1";
    }
    else
    {
        cout<<ans;
    }
    
}