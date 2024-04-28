#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool detectCycle(vector<vector<int>> &graph, int src)
{
    vector<bool> vis(graph.size(), false);
    queue<int> q;
    q.push(src);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            if (vis[vtx])
                continue;
            vis[vtx] = true;
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    q.push(e);
                }
            }
        }
        level++;
    }
}

int main()
{
    return 0;
}