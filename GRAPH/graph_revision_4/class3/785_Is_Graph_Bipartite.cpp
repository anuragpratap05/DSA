#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
// bool isCyclic(vector<vector<int>> &graph, int src)
// {
//     vector<bool> vis(graph.size(), false);
//     queue<int> q;
//     q.push(src);
//     int level = 0;
//     while (!q.empty())
//     {
//         int size = q.size();
//         while (size--)
//         {
//             int vtx = q.front();
//             q.pop();
//             if (vis[vtx])
//             {
//                 return true;
//                 // cout << "cycle at " << vtx << endl;
//                 // continue;
//             }
//             vis[vtx] = true;
//             // cout << "visited " << vtx << " at level " << level << endl;
//             for (int e : graph[vtx])
//             {
//                 if (!vis[e])
//                 {
//                     q.push(e);
//                 }
//             }
//         }
//         level++;
//     }
//     return false;
// }

bool hasOddLenCycle(vector<vector<int>> &graph, int src, vector<int> &vis)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int vtx = p.first;
            int clr = p.second;
            if (vis[vtx] != -1)
            {
                if (vis[vtx] != clr)
                {
                    cout << "prev vis " << vtx << " with " << vis[vtx] << " & now with " << clr << endl;
                    return true;
                }
                else
                {
                    cout << "even cycle at " << vtx << endl;
                }
                continue;
            }
            vis[vtx] = clr;
            for (int e : graph[vtx])
            {
                if (vis[e] == -1)
                {
                    int newClr = 1 - clr;
                    q.push({e, newClr});
                }
            }
        }
        level++;
    }
    return false;
}

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == -1)
        {
            if (hasOddLenCycle(graph, i, vis))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph(5, vector<int>());
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 2);
    // addEdge(graph, 2, 1);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    // hasOddLenCycle(graph, 0);
    return 0;
}