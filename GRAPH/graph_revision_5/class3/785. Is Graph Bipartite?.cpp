#include <bits/stdc++.h>
using namespace std;
bool cyclePresent(vector<vector<int>> &graph, int src, vector<bool> &vis)
{
    queue<int> q;

    q.push(src);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            if (vis[vtx])
            {
                return true;
            }
            vis[vtx] = true;
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    q.push(e);
                }
            }
        }
        // cout << endl;
        level++;
    }
    return false;
}

bool hasOddLenCycle(vector<vector<int>> &graph, vector<int> &vis, int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[0] = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int vtx = p.first;
            int clr = p.second;
            for (int e : graph[vtx])
            {
                if (vis[e] == -1)
                {
                    q.push({e, abs(clr - 1)});
                    vis[e] = abs(clr - 1);
                }
                else if (vis[e] == clr)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> vis1(graph.size(), false);
    bool acyclic = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis1[i])
        {
            bool hasCycle = cyclePresent(graph, i, vis1);
            acyclic = acyclic || hasCycle;
        }
    }
    if (!acyclic)
    {
        return true;
    }

    vector<int> vis(graph.size(), -1);

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
        {
            bool hasCycle = hasOddLenCycle(graph, vis, i);
            if (hasCycle)
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