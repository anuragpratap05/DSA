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
vector<int > vec;
void bfs_cyclefind_method(vector<vector<edge>>& graph,int src,vector<bool>& vis)
{
    queue<int> q;
    q.push(src);
    int level=0;
    int c=0;
    while(!q.empty())
    {
        int size=q.size();
        cout<<"level:"<<level<<"->";
        while(size--)
        {
            int vtx=q.front();
            
            q.pop();

            if(vis[vtx])
            {
                cout<<"cycle ";
                vec.push_back(c);
                c=0;
                continue;
            }
            c++;
            cout<<vtx<<",";
            vis[vtx]=true;
            for(edge e:graph[vtx])
            {
                if(!vis[e.v])
                    q.push(e.v);
            }

        }
        level++;
        cout<<endl;

    }
}

int main()
{
     int V=9;
    vector<vector<edge>> graph(V,vector<edge>());

    addedge(graph,0,1,10);
    addedge(graph,0,3,10);
    addedge(graph,1,2,10);
    addedge(graph,2,3,40);

    addedge(graph,2,7,20);
    addedge(graph,2,8,40);
    addedge(graph,7,8,40);

    

    addedge(graph,3,4,2);
    addedge(graph,4,5,2);
    addedge(graph,4,6,8);
    addedge(graph,5,6,3);
    //addedge(graph,0,6,5);
    vector<bool >vis(V,false);
    bfs_cyclefind_method(graph,0,vis);

    for(int x:vec)
    {
        cout<<x<<" ";
    }


    return 0;
}