#include<bits/stdc++.h>
using namespace std;
int size_of_compo;
// global type dfs
void dfs(vector<vector<int>>& graph,int src,vector<bool>& vis)
{
    int c=0;
    vis[src]=true;
    size_of_compo+=1;
    for(int e:graph[src])
    {
        if(!vis[e])
        {
            dfs(graph,e,vis);
        }
    }
    return ;
}

// return type dfs
int dfs_return_type(vector<vector<int>>& graph,int src,vector<bool>& vis)
{
    int size=0;
    vis[src]=true;
    
    for(int e:graph[src])
    {
        if(!vis[e])
        {
           size+= dfs_return_type(graph,e,vis);
        }
    }
    return size+1;
}
void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int gcc(vector<vector<int>>& graph,int cables_left)
{
    int n=graph.size();
    vector<bool> vis(n,false);
    int c=0;

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            c++;
            size_of_compo=0;
            dfs(graph,i,vis);
            cables_left-=  size_of_compo-1;
            
        }
    }

    if(cables_left<c-1)
    {
        return -1;
    }
    
    return c-1;
}


int makeConnected(int n, vector<vector<int>>& connections)
{
    vector<vector<int>> graph(n,vector<int>());
    int cables_left=connections.size();
    for(auto vec:connections)
    {
        addedge(graph,vec[0],vec[1]);
    }
    return gcc(graph,cables_left);
}

int main()
{
   int n = 6;
   vector<vector<int>>  connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
   makeConnected(n,connections);
    return 0;
}