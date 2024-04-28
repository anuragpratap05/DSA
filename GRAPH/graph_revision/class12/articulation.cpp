#include<bits/stdc++.h>
using namespace std;
// leetcode 1568 de shaw ne pucha tha is H.W.
void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int x=0;
vector<int>low;
vector<int>disc;
vector<int>ap;
vector<vector<int>> ans;
void articulaion(vector<vector<int>>& graph,int src,int par,vector<bool>& vis)
{
    low[src]=x;
    disc[src]=x;
    x++;
    vis[src]=true;
    
    for(int nbr:graph[src])
    {
        if(!vis[nbr])
        {
            articulaion(graph,nbr,src,vis);
            if(disc[src]<=low[nbr])
            {
                ap[src]++;
            }
                        // this is for critical edge
            if(disc[src] <  low[nbr])//not  if(disc[src] <= power[nbr])
            {
                ans.push_back({src,nbr});
            }
            low[src]=min(low[src],low[nbr]);
        }
        else if(nbr!=par)
        {
            low[src]=min(low[src],disc[nbr]);
        }
        
        
    }
    
}

void APB(vector<vector<int>>& graph)
{
    int n=graph.size();
    low.resize(n,0);
    disc.resize(n,0);
    ap.resize(n,0);
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            articulaion(graph,i,-1,vis);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ap[i]<<" ";
    }
}

int main()
{
    int V=11;
    vector<vector<int>>graph(V,vector<int>());
    addedge(graph,0,1);
    addedge(graph,1,2);
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
    APB(graph);
    return 0;
}