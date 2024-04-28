#include<bits/stdc++.h>
using namespace std;

void createit(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
bool haspath(vector<vector<int>>& graph,int src,int dest,vector<bool>& visited)
{
    if(src== dest)
    {
        return true;
    }
    visited[src]=true;

    for(int i=0;i<graph[src].size();i++)
    {
        int nsrc=graph[src][i];
        if(!visited[nsrc])
        {
            
            bool isfound=haspath(graph,nsrc,dest,visited);
            
            if(isfound)
            {
                return true;
            }
        }

    }
    //visited[src]=false;
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int start, int end)
{
    vector<vector<int>> graph(n,vector<int>());

    for(auto edge:edges)
    {
        createit(graph,edge[0],edge[1]);
    }

    vector<bool> vis(n,false);
    return haspath(graph,start,end,vis);



}

int main()
{
    
    return 0;
}