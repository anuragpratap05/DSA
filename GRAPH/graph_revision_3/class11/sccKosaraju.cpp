#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> &grps)
{
    for (auto &vec : grps)
    {
        for (int e : vec)
        {
            cout << e;
        }
        cout << "-->";
    }
}
void addEdge(vector<vector<int>> &graph, vector<vector<int>> &reversedGraph, int u, int v)
{
    graph[u].push_back(v);
    reversedGraph[v].push_back(u);
}

void dfs(vector<vector<int>> &graph, int src, vector<bool> &vis, vector<int> &ans)
{
    vis[src] = true;
    for (int e : graph[src])
    {
        if (!vis[e])
        {
            dfs(graph, e, vis, ans);
        }
    }
    ans.push_back(src);
}

void kosaraju(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> graph(n, vector<int>());
    vector<vector<int>> reversedGraph(n, vector<int>());
    for (vector<int> &vec : edges)
    {
        addEdge(graph, reversedGraph, vec[0], vec[1]);
    }
    vector<bool> vis(n, false);
    vector<int> postArr;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(graph, i, vis, postArr);
        }
    }

    reverse(postArr.begin(), postArr.end());
    vector<bool> vis2(n, false);

    vector<vector<int>> grps;
    for (int i = 0; i < n; i++)
    {
        int e = postArr[i];
        // cout << e << " ";
        if (!vis2[e])
        {
            // cout << "aya" << endl;
            vector<int> ans;
            dfs(reversedGraph, e, vis2, ans);
            grps.push_back(ans);
        }
    }
    display(grps);
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 3}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 7}, {9, 11}};
    kosaraju(edges, 12);
    return 0;
}