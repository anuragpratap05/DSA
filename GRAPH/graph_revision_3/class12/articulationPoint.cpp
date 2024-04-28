#include <bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int x = 0;

void articulationPointHelp(vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, vector<bool> &vis, int src, int par, vector<int> &aP)
{
    disc[src] = low[src] = x;
    x++;
    vis[src] = true;
    for (int n : graph[src])
    {
        if (!vis[n])
        {
            articulationPointHelp(graph, disc, low, vis, n, src, aP);
            if (disc[src] <= low[n])// articulation point
            {
                aP[src]++;
            }
            if(disc[src]<low[n])
            {
                cout << "articulation edge b/w " << src << "and" << n;
            }
            low[src] = min(low[src], low[n]);
        }
        else if (par != n)
        {
            low[src] = min(low[src], disc[n]);
        }
    }
}

void articulationPoint(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> disc(n, 1e6);
    vector<int> low(n, 0);
    vector<int> aP(n, 0);
    aP[0] = -1;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cout << i << endl;
            articulationPointHelp(graph, disc, low, vis, i, -1, aP);
        }
    }
    for (int e : aP)
    {
        cout << e << " ";
    }
}

int main()
{
    int V = 11;
    vector<vector<int>> graph(V, vector<int>());
    addedge(graph, 0, 1);
    addedge(graph, 1, 2);
    addedge(graph, 1, 4);
    addedge(graph, 1, 5);
    addedge(graph, 4, 3);
    addedge(graph, 4, 5);

    addedge(graph, 4, 6);
    addedge(graph, 6, 7);
    addedge(graph, 7, 8);

    addedge(graph, 7, 9);

    addedge(graph, 8, 9);

    addedge(graph, 9, 10);
    addedge(graph, 10, 6);
    articulationPoint(graph);
    return 0;
}