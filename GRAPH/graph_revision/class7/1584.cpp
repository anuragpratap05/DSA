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


int findwt(vector<int>& p1,vector<int>& p2)
{
    int a=abs(p1[0]-p2[0]);
    int b=abs(p1[1]-p2[1]);
    return a+b;
}
struct comp{
    bool operator()(vector<int>& a,vector<int>& b)
    {
        return a[2]>b[2];
    }
};
int prims(vector<vector<edge>>& graph,int src,vector<bool>& vis)
{
    priority_queue<vector<int>,vector<vector<int>>,comp> pq;
    pq.push({0,-1,0,0});
    int ans=0;
    
    while(!pq.empty())
    {
        vector<int> node=pq.top();
        pq.pop();
        int vtx=node[0];
        int par=node[1];
        int wt=node[2];
        int wsf=node[3];

        if(vis[vtx])
        {
            continue;
        }
        vis[vtx]=true;
        ans+=wt;
        //cout<<par<<"-->"<<vtx<<","<<wt<<endl;
        //cout<<vtx<<"-->"<<wsf<<endl;
        for(edge e:graph[vtx])
        {
            if(!vis[e.v])
            {
                pq.push({e.v,vtx,e.w,wsf+e.w});
            }
        }

    }
    return ans;
}

int minCostConnectPoints(vector<vector<int>>& points)
{
    int n=points.size();
    
    vector<vector<edge>>graph(n,vector<edge>());
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            addedge(graph,i,j,findwt(points[i],points[j]));
            //edges.push_back({findwt(points[i],points[j]),i,j});
        }
    }
    vector<bool> vis(n,false);
    return prims(graph,0,vis);


    //sort(edges.begin(),edges.end());
    //return unionfind(edges);
}

int main()
{
    return 0;
}