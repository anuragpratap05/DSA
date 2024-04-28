#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool hasPath(vector<vector<int>> &graph, int src, int dest, vector<bool> &vis)
{
    if (src == dest)
    {
        return true;
    }
    vis[src] = true;
    bool res = false;
    for (int v : graph[src])
    {
        if (!vis[v])
        {
            res = res || hasPath(graph, v, dest, vis);
        }
    }
    return res;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n, vector<int>());
    for (auto &vec : edges)
    {
        addEdge(graph, vec[0], vec[1]);
    }
    vector<bool> vis(n, false);
    return hasPath(graph, source, destination, vis);
}
// [ [ 0, 1 ], [ 1, 2 ], [ 2, 0 ] ]
int main()
{
    return 0;
}