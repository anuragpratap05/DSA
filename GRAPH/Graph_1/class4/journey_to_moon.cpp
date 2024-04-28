#include<bits/stdc++.h>
using namespace std;


void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int bfs(vector<vector<int>>& graph,int src,vector<bool>& vis)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    int c=1;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int vtx=q.front();

            for(int e:graph[vtx])
            {
                if(!vis[e])
                {
                    vis[e]=true;
                    c++;
                }
            }
        }
    }
    return c;
}

int journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<bool> vis(n,false);
    vector<vector<int>> graph(n,vector<int>());
    for(int i=0;i<astronaut.size();i++)
    {
        addedge(graph,astronaut[i][0],astronaut[i][1]);
    }
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            int c=bfs(graph,i,vis);
            ans.push_back(c);
        }
    }

}


int main()
{
    return 0;
}