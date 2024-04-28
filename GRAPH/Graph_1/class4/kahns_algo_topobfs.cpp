#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
}

void kahns_topological_bfs(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<int> indegree(n,0);
    
    for(vector<int>& v:graph)
    {
        for(int e:v)
        {
            indegree[e]++;
        }
    }
    queue<int>q;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int vtx=q.front();
            q.pop();
            ans.push_back(vtx);

            for(int e:graph[vtx])
            {
                if(--indegree[e]==0)
                {
                    q.push(e);
                }
            }
        }
        level++;
    }
    for(int e:ans)
    {
        cout<<e<<" ";
    }
}


int main()
{
    int V=8;
    vector<vector<int>> graph(V,vector<int>());
    addedge(graph,0,1);
    addedge(graph,0,2);
    addedge(graph,2,1);
    addedge(graph,2,3);
    addedge(graph,2,4);
    addedge(graph,1,3);
    addedge(graph,6,3);
    addedge(graph,4,5);
    addedge(graph,5,6);
    addedge(graph,5,7);

    kahns_topological_bfs(graph);

    return 0;
}