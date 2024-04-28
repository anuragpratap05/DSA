#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
}

void dfs(vector<vector<int>>& graph,int src,vector<bool>& vis,vector<int >& ans)
{
    vis[src]=true;
    for(int e:graph[src])
    {
        if(!vis[e])
        {
            dfs(graph,e,vis,ans);
        }
    }
    ans.push_back(src);
}


void topological_dfs(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<bool> vis(n,false);
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(graph,i,vis,ans);
        }
    }
    for(int e:ans)
    {
        cout<<e<<" ";
    }
}

int main()
{
    int V=8;
    vector<vector<int>> graph(V,vector<int>());
    addedge(graph,0,1);
    addedge(graph,0,2);
    addedge(graph,2,1);
    addedge(graph,2,3);
    addedge(graph,2,4);
    addedge(graph,1,3);
    addedge(graph,6,3);
    addedge(graph,4,5);
    addedge(graph,5,6);
    addedge(graph,5,7);
    topological_dfs(graph);
    return 0;
}