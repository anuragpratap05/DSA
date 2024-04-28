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
        return true;

    vis[src] = true;
    bool found = false;
    for (int ele : graph[src])
    {
        if (!vis[ele])
            found = found || dfs(graph, ele, dest, vis);
    }
    return found;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n, vector<int>());
    for (vector<int> &edge : edges)
        addEdge(graph, edge[0], edge[1]);
    vector<bool> vis(n, false);
    return dfs(graph, source, destination, vis);
}

int main()
{
    return 0;
}