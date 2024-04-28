#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], vector<bool> &vis, int src, vector<int> &sa)
{
    int cnt = 0;
    vis[src] = true;
    for (int e : adj[src])
    {
        if (!vis[e])
        {
            cnt += dfs(adj, vis, e, sa);
        }
    }
    sa.push_back(src);
    return cnt + 1;
}

int findMotherVertex(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> sa;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(adj, vis, i, sa);
        }
    }
    int prabalDawedar = sa[sa.size() - 1];
    vector<bool> vis2(V, false);
    sa.clear();
    int cnt = dfs(adj, vis2, prabalDawedar, sa);
    return cnt == V ? prabalDawedar : -1;
}

int main()
{
    return 0;
}