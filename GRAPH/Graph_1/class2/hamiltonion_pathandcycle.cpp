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
int findedge(vector<vector<edge>>& graph,int u,int v)
{
    int n=graph[u].size();
    for(int i=0;i<n;i++)
    {
        edge ele=graph[u][i];
        if(ele.v==v)
        {
            return i;
        }
    }
    return -1;
}

void hamiltonion_pathandcycle(vector<vector<edge>>& graph,int src,int osrc,int c,string psf,vector<bool>& visited,vector<string>& vec)
{
    //cout<<"aya";
    if(c==graph.size()-1)
    {
        psf+=to_string(src);
        

        int idx=findedge(graph,src,osrc);
        if(idx!=-1)
        {
            psf+= "*";
        }
        vec.push_back(psf);
    }
    visited[src]=true;
    for(edge e:graph[src])
    {
        if(!visited[e.v])
        {
            hamiltonion_pathandcycle(graph,e.v,osrc,c+1,psf+ to_string(src), visited,vec);
        }
    }
    visited[src]=false;
    return;
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
    addedge(graph,0,6,5);
      vector<string> vec;
      vector<bool> visited(V,false);

    hamiltonion_pathandcycle(graph,0,0,0,"",visited,vec);

    for(auto e:vec)
    {
        cout<<e<<" ";
    }
    return 0;
}