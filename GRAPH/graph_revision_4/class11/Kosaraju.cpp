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

void dfs(vector<vector<int>> &myGarph, int src, vector<bool> &vis, vector<int> &sa)
{
    vis[src] = true;
    for (int e : myGarph[src])
    {
        if (!vis[e])
        {
            dfs(myGarph, e, vis, sa);
        }
    }
    sa.push_back(src);
}

void Kosaraju(vector<vector<int>> &edges, int n)
{
    vector<vector<int>> graph(n, vector<int>());
    vector<vector<int>> reversedGraph(n, vector<int>());

    for (auto &vec : edges)
    {
        addEdge(graph, reversedGraph, vec[0], vec[1]);
    }
    vector<int> postArr;
    vector<bool> postVis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!postVis[i])
        {
            dfs(graph, i, postVis, postArr);
        }
    }
    reverse(postArr.begin(), postArr.end());
    vector<bool> vis(n, false);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int e = postArr[i];
        if (!vis[e])
        {
            vector<int> sa;
            dfs(reversedGraph, e, vis, sa);

            // cout << endl;
            ans.push_back(sa);
        }
    }
    display(ans);
}

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 3}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 7}, {9, 11}};
    Kosaraju(edges, 12);
    return 0;
}