#include<bits/stdc++.h>
using namespace std;

// leetcode 1568 is HW
class  edge{
    public:
    int v,w;
    edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};

void addedge(vector<vector<edge>>& graph,int u,int v)
{
    graph[u].push_back(edge(v,0));
    graph[v].push_back(edge(u,0));
}
int x=0;
vector<int> power,disc,vis,ap;
vector<vector<int>> ans;
void dfs(vector<vector<edge>>& graph,int src,int par)
{
    disc[src]=power[src]=x;
    vis[src]=true;
    x++;
    for(edge e:graph[src])
    {
        int nbr=e.v;
        if(!vis[nbr])
        {
            dfs(graph,nbr,src);
            if(disc[src]<=power[nbr])
            {
                ap[src]++;
            }
            // this is for critical edge
            if(disc[src] <  power[nbr])//not  if(disc[src] <= power[nbr])
            {
                ans.push_back({src,nbr});
            }
            power[src]=min(power[src],power[nbr]);
        }
        else if(nbr!=par)
        {
            power[src]=min(power[src],disc[nbr]);
        }
    }

}

void APB(int n,vector<vector<edge>>& graph)
{
     power.resize(n,0);
     disc.resize(n,0);
     vis.resize(n,false);
     ap.resize(n,0);
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            ap[i]=-1;
            dfs(graph,i,-1);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ap[i]<<" ";
    }

}

int main()
{
    //vector<vector<edge>> graph (n,vector<edge>());
    int V=11;
    vector<vector<edge>>graph(V,vector<edge>());
    addedge(graph,1,2);
    addedge(graph,0,1);
    addedge(graph,1,4);
    addedge(graph,1,5);
    addedge(graph,4,3);
    addedge(graph,4,5);

    addedge(graph,4,6);
    addedge(graph,6,7);
    addedge(graph,7,8);

    addedge(graph,7,9);
    addedge(graph,8,9);

    addedge(graph,9,10);
    addedge(graph,10,6);
    APB(V,graph);
    return 0;
}