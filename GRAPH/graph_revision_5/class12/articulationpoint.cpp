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
void dfs(vector<vector<int>> graph, int src, vector<bool> &vis, int par)
{
    disc[src] = x;
    low[src] = x;
    x++;
    vis[src] = true;
    for (int nbr : graph[src])
    {
        if (!vis[nbr])
        {
            dfs(graph, nbr, vis, src);
            if (disc[src] <= low[nbr])
            {
                cout << "aya" << endl;
                AP[src]++;
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

void articulationPoint(int n, vector<vector<int>> graph)
{
    disc.resize(n, 0);
    low.resize(n, 0);
    AP.resize(n, 0);
    AP[0] = -1;
    vector<bool> vis(n, false);
    dfs(graph, 0, vis, -1);
    for (int e : AP)
    {
        cout << e << ' ';
    }
}

int main()
{
    int V = 11;
    vector<vector<int>> graph(V, vector<int>());
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 5);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 5);

    addEdge(graph, 4, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);

    addEdge(graph, 7, 9);

    addEdge(graph, 8, 9);

    addEdge(graph, 9, 10);
    addEdge(graph, 10, 6);
    articulationPoint(V, graph);
    return 0;
}