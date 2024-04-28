#include <bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(int(v));
    graph[v].push_back(int(u));
}
void dfs(vector<vector<int>> &graph, int src, vector<bool> &vis)
{
    vis[src] = true;
    for (int e : graph[src])
    {
        if (!vis[e])
        {
            dfs(graph, e, vis);
        }
    }
    //vis[src] = false;
}

int get_gcc(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> vis(n, false);
    int compo = 0;

    for (int i = 0; i < n; i++)
    {
        
        if (!vis[i])
        {
            compo++;
            dfs(graph, i, vis);
        }
    }
    return compo;
}

int main()
{
    int V = 9;
    vector<vector<int>> graph(V, vector<int>());

    addedge(graph, 0, 1);
    addedge(graph, 0, 3);
    addedge(graph, 2, 3);
    addedge(graph, 1, 2);

    addedge(graph, 2, 7);
    addedge(graph, 2, 8);
    addedge(graph, 7, 8);

   // addedge(graph, 3, 4);

    addedge(graph, 4, 5);
    addedge(graph, 4, 6);
    addedge(graph, 5, 6);

    cout << get_gcc(graph);

    return 0;
}