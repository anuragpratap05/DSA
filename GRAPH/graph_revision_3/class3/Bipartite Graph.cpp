#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
bool isCyclic(vector<vector<int>> &graph, int src, vector<bool> &vis)
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
            // cout << vtx << ",";
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

bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    bool cyclePresent = false;
    vector<bool> vis(graph.size(), false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (isCyclic(graph, i, vis))
            {
                cyclePresent = true;
                break;
            }
        }
    }
    if (!cyclePresent)
    {
        return true;
    }

    vector<int> arr(V, -1);
    queue<pair<int, int>> q;
    for (int i = 0; i < V; i++)
    {
        if (arr[i] == -1)
        {
            q.push({i, 0});
            arr[i] = 0;
            while (!q.empty())
            {
                int size = q.size();
                while (size--)
                {
                    pair<int, int> p = q.front();
                    int vtx = p.first;
                    int clr = p.second;
                    q.pop();
                    for (int e : graph[vtx])
                    {
                        int newClr = abs(clr - 1);
                        if (arr[e] == -1)
                        {
                            arr[e] = newClr;
                            q.push({e, newClr});
                        }
                        else
                        {
                            if (arr[e] != newClr)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    return 0;
}