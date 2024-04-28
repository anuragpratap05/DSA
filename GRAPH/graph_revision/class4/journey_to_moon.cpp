#include<bits/stdc++.h>
using namespace std;

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
            
            dfs_return_type(graph,i,vis);
            //cables_left-=  size_of_compo-1;
            
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
int journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<bool> vis;
    
}

int main()
{
    return 0;
}