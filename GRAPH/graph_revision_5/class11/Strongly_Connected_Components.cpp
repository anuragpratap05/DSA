#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &vis, int src, vector<int> &ans, bool store)
{
    vis[src] = true;
    for (int e : graph[src])
    {
        if (!vis[e])
        {
            dfs(graph, vis, e, ans, store);
        }
    }
    if (store)
        ans.push_back(src);
}

void display(vector<vector<int>> &graph)
{
    for (vector<int> &vec : graph)
    {
        for (int e : vec)
        {
            cout << e << ' ';
        }
        cout << endl;
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<bool> vis(V, false);
    vector<int> ans;

    vector<vector<int>> reversedGraph(V, vector<int>());

    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            reversedGraph[v].push_back(i);
        }
        if (!vis[i])
        {
            dfs(adj, vis, i, ans, true);
        }
    }
    vector<bool> vis2(V, false);
    vector<int> ans2;
    int cnt = 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        int ele = ans[i];
        if (!vis2[ele])
        {
            cnt++;
            dfs(reversedGraph, vis2, ele, ans2, false);
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> graph = {{2, 3}, {0}, {1}, {4}};
    int V = 5;
    kosaraju(V, graph);
    return 0;
}