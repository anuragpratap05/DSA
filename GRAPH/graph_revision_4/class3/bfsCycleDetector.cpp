#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void bfsCycleWala(vector<vector<int>> &graph, int src)
{
    vector<bool> vis(graph.size(), false);
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
                cout << "cycle at " << vtx << endl;
                continue;
            }
            vis[vtx] = true;
            cout << "visited " << vtx << " at level " << level << endl;
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    q.push(e);
                }
            }
        }
        level++;
    }
}

void bfsoptimized(vector<vector<int>> &graph, int src)
{
    vector<bool> vis(graph.size(), false);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();

            cout << "visited " << vtx << " at level " << level << endl;
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    q.push(e);
                    vis[e] = true;
                }
            }
        }
        level++;
    }
}

int main()
{
    int V = 7;
    vector<vector<int>> graph(V, vector<int>());
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 2);

    // addEdge(graph, 2, 7, 2);
    // addEdge(graph, 2, 8, 4);
    // addEdge(graph, 7, 8, 3);

    addEdge(graph, 3, 4);

    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 5, 6);
    bfsoptimized(graph, 0);
    return 0;
}