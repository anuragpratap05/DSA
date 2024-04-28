#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
}
bool dfs(vector<vector<int>>& graph,int src,vector<int>& vis,vector<int >& ans)
{
    vis[src]=1;
    for(int e:graph[src])
    {
        if(vis[e]==1)
        {
           return true; 
        }
        if(vis[e]==0)
        {
          bool cycle=  dfs(graph,e,vis,ans);
            if(cycle)
            {
                return true;
            }
        }
        
    }
    vis[src]=2;
    ans.push_back(src);
    return false;
}

// void dfs(vector<vector<int>>& graph,int src,vector<int>& vis,vector<int >& ans)
// {
//     vis[src]=1;
//     for(int e:graph[src])
//     {
//         if(vis[e]==0)
//         {
//             dfs(graph,e,vis,ans);
//         }
//         if(vis[e]==1)
//         {
            
//         }
//     }
//     vis[src]=2;
//     ans.push_back(src);
// }


void topological_dfs(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<int> vis(n,0);
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
           bool cycle=dfs(graph,i,vis,ans);
           if(cycle)
           {
               cout<<"cycle found"<<endl;
               break;
           }
        }
    }
    for(int e:ans)
    {
        cout<<e<<" ";
    }
}

int main()
{
    int V=2;
    vector<vector<int>> graph(V,vector<int>());
    addedge(graph,1,0);
    // addedge(graph,0,1);
    // addedge(graph,0,2);
    // addedge(graph,2,1);
    // addedge(graph,2,3);
    // addedge(graph,2,4);
    // addedge(graph,1,3);
    // addedge(graph,6,3);
    // addedge(graph,4,5);
    // addedge(graph,5,6);
    // addedge(graph,5,7);
   // addedge(graph,3,5);//cycle maker
    topological_dfs(graph);
    return 0;
}