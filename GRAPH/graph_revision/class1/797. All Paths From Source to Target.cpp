#include<bits/stdc++.h>
using namespace std;


   void createit(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
    //graph[v].push_back(u);
}
vector<vector<int>> ans;
int print_all(vector<vector<int>>& graph,int src,int dest,vector<bool>& vis,vector<int>& v)
{
    if(src==dest)
    {
        //psf+=to_string(dest);
        //cout<<psf<<endl;
        
        // for(int e:v)
        // {
        //     cout<<e<<" ";
        // }
        
        
       // cout<<endl;
        v.push_back(dest);
        ans.push_back(v);
        v.pop_back();
       // v.clear();

        return 1;
    }
    vis[src]=true;
    int c=0;
    for(int i=0;i<graph[src].size();i++)
    {
        int e=graph[src][i];
        if(!vis[e])
        {
            v.push_back(src);
            c+=print_all(graph,e,dest,vis,v);
            v.pop_back();
        }
    }
    
    vis[src]=false;
    return c;
}
void printit(vector<vector<int>>& graph)
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"-->";
        for(int e:graph[i])
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}
int possible_paths(vector<vector<int>>edges, int n, int s, int d)
{
    vector<bool> vis(n,false);
    vector<vector<int>> graph(n,vector<int>());
    // for(auto edge:edges)
    // {
    //     createit(graph,edge[0],edge[1]);
    // }
    for(int i=0;i<n;i++)
    {
        int u=i;
        for(int v:edges[i])
        {
           createit(graph,u,v); 
        }
    }
    //printit(graph);
    vector<int> v;
    return print_all(graph,s,d,vis,v);
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       // vector<vector<int>> input={{1,2},{3},{3},{}};
    int n=graph.size();
        possible_paths(graph,n,0,n-1);
        return ans;
    }

int main()
{
    return 0;
}