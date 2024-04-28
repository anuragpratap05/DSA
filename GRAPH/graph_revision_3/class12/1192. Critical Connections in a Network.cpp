#include <bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int x = 0;
void articulationPointHelp(vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, vector<bool> &vis, int src, int par, vector<int> &aP, vector<vector<int>> &ans)
{
    disc[src] = low[src] = x;
    x++;
    vis[src] = true;
    for (int n : graph[src])
    {
        if (!vis[n])
        {
            articulationPointHelp(graph, disc, low, vis, n, src, aP, ans);
            if (disc[src] <= low[n]) // articulation point
            {
                aP[src]++;
            }
            if (disc[src] < low[n])
            {
                ans.push_back({src, n});
                // cout << "articulation edge b/w " << src << "and" << n;
            }
            low[src] = min(low[src], low[n]);
        }
        else if (par != n)
        {
            low[src] = min(low[src], disc[n]);
        }
    }
}

vector<vector<int>> articulationPoint(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> disc(n, 1e6);
    vector<int> low(n, 0);
    vector<int> aP(n, 0);
    aP[0] = -1;
    vector<bool> vis(n, false);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cout << i << endl;
            articulationPointHelp(graph, disc, low, vis, i, -1, aP, ans);
        }
    }
    for (int e : aP)
    {
        cout << e << " ";
    }
    return ans;
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> graph(n, vector<int>());
    for (auto &vec : connections)
    {
        addedge(graph, vec[0], vec[1]);
    }
    return articulationPoint(graph);
}

int main()
{
    return 0;
}