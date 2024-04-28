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

void graph_inv(vector<vector<int>>& graph,vector<vector<int>>& newgraph)
{
    int n=graph.size();
    
    for(int u=0;u<n;u++)
    {
        for(int v:graph[u])
        {
            addedge(newgraph,v,u);
        }
    }


}
void display(vector<vector<int>>& graph)
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(int e:graph[i])
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}
void kosaraju(vector<vector<int>>& graph)
{
    //1 find topological order
    //2. inverse graph
    //3. apply dfs

    //1.
    int n=graph.size();
    
    vector<bool> vis(n,false);
    vector<vector<int>> newgraph(n,vector<int>());
    
    vector<int> ans;
   
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(graph,i,vis,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    display(graph);
    cout<<endl;
    for(int e:ans)
    {
        cout<<e<<" ";
    }
    
    cout<<endl;
    //2.
    graph_inv(graph,newgraph);
    cout<<endl<<endl;
    display(newgraph);

    
    vector<bool> nvis(n,false);
    vector<int > na;
    //3.
    for(int i=0;i<ans.size();i++)
    {
        
        //s+=to_string(i);
        int vtx=ans[i];
        if(nvis[vtx]==false)
        {
            //cout<<"aya"<<endl;
            dfs(newgraph,vtx,nvis,na);
            for(int e:na)
            {
                cout<<e<<" ";
            }
            cout<<endl;
            na.clear();
        }
    }
    
    
}

int main()
{
    int V=3;
    vector<vector<int>> graph(V,vector<int>());
    addedge(graph,0,1);
    addedge(graph,2,1);
    // addedge(graph,0,1);
    // addedge(graph,1,2);
    // addedge(graph,2,0);

    // addedge(graph,2,3);
    // addedge(graph,3,4);
    // addedge(graph,4,5);
    // addedge(graph,5,6);
    // addedge(graph,6,3);

    // addedge(graph,6,7);

    // addedge(graph,7,8);
    // addedge(graph,8,9);
    // addedge(graph,9,11);
    // addedge(graph,9,10);
    // addedge(graph,10,7);
    kosaraju(graph);
    return 0;
}