#include<bits/stdc++.h>
using namespace std;


class pair_
{
    public:
    int wt=0;
    string psf="";

    pair_(int wt,string psf)
    {
        this->wt=wt;
        this->psf=psf;
    }
};

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

pair_ longest_path(vector<vector<edge>>& graph,int src,int dest,vector<bool>& vis)
{
    if(src==dest)
    {
        pair_ basep=pair_(0,to_string(dest));
        return basep;
    }

    pair_ myans= pair_(-1,"");
    vis[src]=true;
    for(int i=0;i<graph[src].size();i++)
    {
        edge e=graph[src][i];
        if(!vis[e.v])
        {
            pair_ recans=longest_path(graph,e.v,dest,vis);
            if(recans.wt!=-1 and recans.wt+e.w>myans.wt)
            {
                myans.wt=recans.wt+e.w;
                myans.psf=to_string(e.v)+recans.psf;
            }
        }
    }
    vis[src]=false;
     
     return myans;
}

int main()
{
    int V=7;
    vector<vector<edge>> graph(V,vector<edge>());

    addedge(graph,0,1,10);
    addedge(graph,0,3,10);
    addedge(graph,1,2,10);
    addedge(graph,2,3,40);

    // addedge(graph,2,7,2);
    // addedge(graph,2,8,4);
    // addedge(graph,7,8,3);
    

    

    addedge(graph,3,4,2);
    addedge(graph,4,5,2);
    addedge(graph,4,6,8);
    addedge(graph,5,6,3);
    vector<bool> vis(V,false);

    pair_ p=longest_path(graph,0,6,vis);
    cout<<p.wt<<"  "<<p.psf<<endl;
    return 0;
}