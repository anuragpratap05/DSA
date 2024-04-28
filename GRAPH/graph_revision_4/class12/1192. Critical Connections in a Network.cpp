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

void dfs(vector<vector<int>> &graph, int src, int par, vector<vector<int>> &ans)
{
    disc[src] = low[src] = x;
    x++;
    for (int nbr : graph[src])
    {
        if (disc[nbr] == -1)
        {
            dfs(graph, nbr, src, ans);
            // if (disc[src] <= low[nbr])//A Point
            // {
            //     AP[src]++;
            // }
            if (disc[src] < low[nbr]) // A edge
            {
                ans.push_back({src, nbr});
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

vector<vector<int>> articulationPoint(int n, vector<vector<int>> graph)
{
    disc.resize(n, -1);
    low.resize(n, -1);
    AP.resize(n, 0);
    AP[0] = -1;
    vector<vector<int>> ans;
    dfs(graph, 0, -1, ans);

    return ans;
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> graph(n, vector<int>());
    for (vector<int> &vec : connections)
    {
        addEdge(graph, vec[0], vec[1]);
    }
    return articulationPoint(n, graph);
}

int main()
{
    return 0;
}