#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
}

void dfs(vector<vector<int>>& graph,int src,vector<bool>& vis,vector<int>& ans)
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

void inverse(vector<vector<int>>& graph,vector<vector<int>>& mygraph)
{
    int n=graph.size();
    
    for(int v=0;v<n;v++)
    {
        for(int u:graph[v])
        {
            mygraph[u].push_back(v);
        }
    }
}
void display(vector<vector<int>>& graph)
{
    for(int i=0;i<graph.size();i++)
    {
        //cout<<i<<"->";
        for(int e:graph[i])
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}
void kosaraju(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<int>ans;
    vector<bool> vis(n,false);
    vector<vector<int>> mygraph(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(graph,i,vis,ans);
        }
    }
    

    inverse(graph,mygraph);
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
    }
    vector<vector<int>>scc;
    vector<int>grps;
    for(int i=ans.size()-1;i>=0;i--)
    {
        int src=ans[i];
        if(!vis[src])
        {
            grps.clear();
            dfs(mygraph,src,vis,grps);
            scc.push_back(grps);
        }

    }
    display(scc);
}

int main()
{
    int V=12;
    vector<vector<int>> graph(V,vector<int>());
    // addedge(graph,0,1);
    // addedge(graph,2,1);
    addedge(graph,0,1);
    addedge(graph,1,2);
    addedge(graph,2,0);

    addedge(graph,2,3);
    addedge(graph,3,4);
    addedge(graph,4,5);
    addedge(graph,5,6);
    addedge(graph,6,3);

    addedge(graph,6,7);

    addedge(graph,7,8);
    addedge(graph,8,9);
    addedge(graph,9,11);
    addedge(graph,9,10);
    addedge(graph,10,7);
    kosaraju(graph);
    return 0;
}