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
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));
}

bool haspath(vector<vector<edge>>& graph,int src,int dest,int n)
{
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(src);
    vis[src]=true;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int vtx=q.front();
            q.pop();

            for(edge e:graph[vtx])
            {
                if(!vis[e.v])
                {
                    vis[e.v]=true;
                    q.push(e.v);
                    if(e.v == dest)
                    {
                        return true;
                    }
                }
            }


        }
        

    }
    return false;
}

void dijkstra(vector<vector<edge>>& graph,int src,int n,vector<int>& dis)
{
    
    vector<bool> vis(n,false);
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
                //par[dest]=nsrc;
                pq.push({wsf+cur_wt,dest});
            }
        }

    }
    

}

int main()
{
    int n,m,k,x,city,a,b;
    cin>>n>>m>>k>>x;
    vector<int > choc;
    for(int i=0;i<k;i++)
    {
        cin>>city;
        choc.push_back(city);
    }
    vector<vector<edge>> graph(n+1,vector<edge>());
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        addedge(graph,u,v,w);

    }

    cin>>a>>b;

    vector<int> atoc(n+1,1e8);
    vector<int> btoc(n+1,1e8);
    dijkstra(graph,a,n+1,atoc);
    dijkstra(graph,b,n+1,btoc);
    int ans=1e8;

    for(int i=0;i<choc.size();i++)
    {
        int vtx=choc[i];
        if(atoc[vtx]!=1e8 and btoc[vtx]<x)
        {
            int val=atoc[vtx]+btoc[vtx];
            ans=min(ans,val);
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