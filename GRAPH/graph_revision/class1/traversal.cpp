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
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
}

int find_edge(vector<vector<edge>>& graph,int u,int v)
{
    for(int i=0;i<graph[u].size();i++)
    {
        edge e=graph[u][i];
        if(e.v==v)
        {
            return i;
        }
    }
    return -1;
}

void remove_edge(vector<vector<edge>>& graph,int u,int v)
{
    int idx=find_edge(graph,u,v);
    graph[u].erase(graph[u].begin()+idx);
}

void display(vector<vector<edge>>& graph)
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"-->";
        for(edge e:graph[i])
        {
            cout<<"("<<e.v<<","<<e.w<<") ";
        }
        cout<<endl;
    }
}

int main()
{
    int V=6;
    vector<vector<edge>> graph(V,vector<edge>());
    addedge(graph,0,1,5);
    addedge(graph,0,2,8);
    //addedge(graph,1,0,5);
    addedge(graph,1,2,10);
    addedge(graph,1,3,2);
    //addedge(graph,1,0,5);
   // addedge(graph,2,0,8);
   // addedge(graph,2,1,10);
    addedge(graph,2,4,14);

   // addedge(graph,3,1,12);
    addedge(graph,3,4,20);
    addedge(graph,3,5,16);

    // addedge(graph,4,2,14);
    // addedge(graph,4,3,20);
    // addedge(graph,4,5,21);

   // addedge(graph,5,3,16);
    addedge(graph,5,4,21);
    display(graph);
    remove_edge(graph,3,4);
    cout<<endl;
    display(graph);
    return 0;
}