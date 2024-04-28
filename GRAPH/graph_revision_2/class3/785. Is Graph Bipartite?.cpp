#include <bits/stdc++.h>
using namespace std;

bool cycle_len(int V, vector<vector<int>> &graph, vector<int> &vis, int src)
{
    queue<pair<int, int>> q;

    q.push({src, 0});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int rn = p.first;
        int clr = p.second;

        if (vis[rn] != -1)
        {
            // cycle
            if (clr != vis[rn])
            {
                return false;
            }
            continue;
        }

        vis[rn] = clr;

        for (int e : graph[rn])
        {
            if (vis[e] == -1)
            {
                int my_c = (clr == 0 ? 1 : 0);
                q.push({e, my_c});
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();

    vector<int> vis1(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (vis1[i] == -1)
        {
            bool x = cycle_len(n, graph, vis1, i);
            if (!x)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    return 0;
}