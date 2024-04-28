#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<int> disc;
vector<int> low;         
vector<int> AP;
int x = 0;
void dfs(vector<vector<int>> &graph, int src, vector<bool> &vis, int par, vector<vector<int>> &ans)
{
    disc[src] = x;
    low[src] = x;
    x++;
    vis[src] = true;
    for (int nbr : graph[src])
    {
        if (!vis[nbr])
        {
            dfs(graph, nbr, vis, src, ans);

            // if (disc[src] <= low[nbr])
            // {
            //     cout << "aya" << endl;
            //     AP[src]++;
            // }
            if (disc[src] < low[nbr])
            {
                ans.push_back({src, nbr});
            }
            low[src] = min(low[src], low[nbr]);
        }
        else
        {
            if (nbr != par)
            {
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
}

vector<vector<int>> articulationPoint(int n, vector<vector<int>> &graph)
{
    disc.resize(n, 0);
    low.resize(n, 0);
    // AP.resize(n, 0);
    // AP[0] = -1;
    vector<bool> vis(n, false);
    vector<vector<int>> ans;
    dfs(graph, 0, vis, -1, ans);
    return ans;
    // for (int e : AP)
    // {
    //     cout << e << ' ';
    // }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> graph(n, vector<int>());
    for (vector<int> &vec : connections)
    {
        int u = vec[0];
        int v = vec[1];
        addEdge(graph, u, v);
    }
    return articulationPoint(n, graph);
}

int main()
{
    return 0;
}