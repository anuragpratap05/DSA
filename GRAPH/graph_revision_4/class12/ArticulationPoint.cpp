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

void dfs(vector<vector<int>> &graph, int src, int par)
{
    disc[src] = low[src] = x;
    x++;
    for (int nbr : graph[src])
    {
        if (disc[nbr] == -1)
        {
            dfs(graph, nbr, src);
            if (disc[src] <= low[nbr])
            {
                AP[src]++;
            }
            low[src] = min(low[src], low[nbr]);
        }
        else
        {
            if (nbr != par)
                low[src] = min(low[src], low[nbr]);
        }
    }
}

void articulationPoint(int n, vector<vector<int>> graph)
{
    disc.resize(n, -1);
    low.resize(n, -1);
    AP.resize(n, 0);
    AP[0] = -1;
    dfs(graph, 0, -1);

    for (int e : AP)
    {
        cout << e << " ";
    }
}

// vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
// {
// }

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