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

void bfs_cycle(vector<vector<edge>>& graph,int src)
{
    queue<int> q;
    vector<bool> vis(graph.size(),false);
    q.push(src);
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        cout<<level<<"-->";
        while(size--)
        {
            int vtx=q.front();
            q.pop();
            if(vis[vtx])
            {
                cout<<"cycle";
                continue;
            }

            vis[vtx]=true;
            cout<<vtx<<" ";
            for(auto nbr:graph[vtx])
            {
                if(!vis[nbr.v])
                {
                    q.push(nbr.v);
                }
            }
        }
        cout<<endl;
        level++;
    }

}


int main()
{
    int V=9;
    vector<vector<edge>> graph(V,vector<edge>());
    addedge(graph,0,1,4);
    addedge(graph,0,7,8);

    addedge(graph,1,7,11);
    addedge(graph,1,2,8);

    addedge(graph,7,8,7);
    addedge(graph,7,6,1);

    addedge(graph,2,8,2);
    addedge(graph,8,6,6);

    addedge(graph,2,3,7);
    addedge(graph,2,5,7);

    addedge(graph,6,5,7);
    addedge(graph,3,5,7);
    addedge(graph,3,4,7);
    addedge(graph,5,4,7);
    bfs_cycle(graph,0);
    
    return 0;
}