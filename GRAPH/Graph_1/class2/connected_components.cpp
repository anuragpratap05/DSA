#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int v,w;
    edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};

void addedge(vector<vector<edge>>& graph,int u,int v,int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));


    
}

void gcchelp(vector<vector<edge>>& graph,int src,vector<bool>& vis)
{
    vis[src]=true;
    for(edge e:graph[src])
    {
        if(!vis[e.v])
        {
           gcchelp(graph,e.v,vis); 
        }
    }
}

int gcc(vector<vector<edge>>& graph)
{
    int n=graph.size();
    vector<bool> vis(n,false);
    int compo=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            compo++;
            gcchelp(graph,i,vis);
        }
    }
    return compo;
}



int main()
{
    int V=7;
    vector<vector<edge>> graph(V,vector<edge>());

    addedge(graph,0,1,10);
    addedge(graph,0,3,10);
    addedge(graph,1,2,10);
    addedge(graph,2,3,40);

    

    

    addedge(graph,3,4,2);
    addedge(graph,4,5,2);
    addedge(graph,4,6,8);
    addedge(graph,5,6,3);
    cout<<gcc(graph);
    
    return 0;
}


