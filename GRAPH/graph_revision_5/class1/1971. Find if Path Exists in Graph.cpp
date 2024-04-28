#include <bits/stdc++.h>
using namespace std;

bool hasPath(vector<vector<int>> &graph, vector<bool> &vis, int src, int dst)
{
    if (src == dst)
    {
        return true;
    }
    vis[src] = true;
    for (int e : graph[src])
    {
        if (!vis[e])
        {
            bool ans = hasPath(graph, vis, e, dst);
            if (ans)
            {
                return true;
            }
        }
    }

    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n, vector<int>());

    for (vector<int> &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n, false);
    return hasPath(graph, vis, source, destination);
}

int main()
{
    return 0;
}