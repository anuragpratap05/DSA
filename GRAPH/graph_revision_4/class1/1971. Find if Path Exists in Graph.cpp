#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
bool dfs(vector<vector<int>> &graph, int src, int dest, vector<bool> &vis)
{
    if (src == dest)
    {
        return true;
    }
    vis[src] = true;
    for (int e : graph[src])
    {
        if (!vis[e])
        {
            if (dfs(graph, e, dest, vis))
            {
                return true;
            }
        }
    }
    // vis[src] = false;
    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n, vector<int>());
    for (auto &e : edges)
    {
        addEdge(graph, e[0], e[1]);
    }
    vector<bool> vis(n, false);
    return dfs(graph, source, destination, vis);
}

int main()
{
    return 0;
}