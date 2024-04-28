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

class pair_
{
    public:
    int vtx,color;
    pair_(int vtx,int color)
    {
        this->vtx=vtx;
        this->color=color;
    }

};

void addedge(vector<vector<edge>>& graph,int u,int v,int w)
{
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
}

bool bfs_cycle(vector<vector<edge>>& graph,int src)
{
    queue<pair_> q;
    vector<bool> vis(graph.size(),false);
    vector<int> prec_color(graph.size(),-1);
    q.push(pair_(src,0));
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        //cout<<level<<"-->";
        while(size--)
        {
            pair_ p=q.front();
            int vtx=p.vtx;
            int color=p.color;
            q.pop();
            if(vis[vtx])
            {
                //cout<<"cycle";
                if(color!=prec_color[vtx])
                {
                    return false;
                }
                continue;
            }

            vis[vtx]=true;
            prec_color[vtx]=color;
            //cout<<vtx<<" ";
            for(auto nbr:graph[vtx])
            {
                if(!vis[nbr.v])
                {
                    int new_c=(color+1)%2;
                    q.push(pair_(nbr.v,new_c));
                }
            }
        }
        cout<<endl;
        level++;
    }
    return true;

}
bool isBipartite(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<vector<edge>> mygraph(n,vector<edge>());
    for(int i=0;i<n;i++)
    {
        for(int e:graph[i])
        {
            addedge(mygraph,i,e,0);
        }
        
    }   
   return bfs_cycle(mygraph,0);
}

int main()
{
    return 0;
}