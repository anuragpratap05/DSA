#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<pair<int,int>>>& graph,int u,int v,int w)
{
    graph[u].push_back(make_pair(v,w));
}

int dijkstra(vector<vector<pair<int,int>>>& graph,int n,int src)
{
    vector<bool> vis(n+1,false);
    vector<int> dis(n+1,1e8);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();

        int wsf=p.first;
        int nsrc=p.second;
        if(vis[nsrc])
        {
            continue;
        }
        dis[nsrc]=wsf;
        vis[nsrc]=true;

        for(auto pa:graph[src])
        {
            int dest=pa.first;
            int wt=pa.second;
            if(!vis[dest])
            {
                pq.push(make_pair(wsf+wt,dest));
            }
            
        }

    }
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==1e8)
        {
            return -1;
        }
        maxi=max(maxi,dis[i]);
    }
    return maxi;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    
    
    vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());

    for(vector<int>& vec:times)
    {
        int u=vec[0];
        int v=vec[1];
        int w=vec[2];
        addedge(graph,u,v,w);
    }

    return dijkstra(graph,n,k);

}

int main()
{
    return 0;
}