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
}
int countPaths(vector<vector<int>> &graph, int src, int dest)
{
    if (src == dest)
    {
        return 1;
    }
    int cnt = 0;
    for (int v : graph[src])
    {
        cnt += countPaths(graph, v, dest);
    }
    return cnt;
}
int possible_paths(vector<vector<int>> edges, int n, int s, int d)
{
    vector<vector<int>> graph(n, vector<int>());
    for (auto &vec : edges)
    {
        addEdge(graph, vec[0], vec[1]);
    }
    return countPaths(graph, s, d);
}

int main()
{
    return 0;
}