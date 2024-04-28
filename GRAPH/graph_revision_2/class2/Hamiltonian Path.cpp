#include <bits/stdc++.h>
using namespace std;
//gfg

bool check_help(vector<vector<int>>& graph, int src, int N, int M, int e, vector<bool> &vis)
{
    if (e == N - 1)
    {
        return true;
    }
    vis[src] = true;
    bool res = false;

    for (int ele : graph[src])
    {
        if (!vis[ele])
        {
            res = res || check_help(graph, ele, N, M, e + 1, vis);
        }
    }

    vis[src] = false;
    return res;
}

void addedge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool check(int N, int M, vector<vector<int>> Edges)
{
    vector<vector<int>> graph(N + 1, vector<int>());

    for (auto &vec : Edges)
    {
        addedge(graph, vec[0], vec[1]);
    }
    vector<bool> vis;

    for (int i = 1; i <= N; i++)
    {
        vis.resize(N + 1, false);
        if (check_help(graph, i, N, M, 0, vis))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}