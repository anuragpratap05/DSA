#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}
bool kans_dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &path, int src)
{
    vis[src] = true;
    path[src] = true;

    for (int e : graph[src])
    {
        if (!vis[e])
        {
            bool ans = kans_dfs(graph, vis, path, e);
            if (!ans)
            {
                return false;
            }
        }
        else
        {
            if (path[e])
            {
                return false;
            }
        }
    }

    path[src] = false;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = numCourses;
    vector<vector<int>> graph(n, vector<int>());

    vector<int> indegree(n, 0);

    for (auto &vec : prerequisites)
    {
        indegree[vec[1]]++;
        addedge(graph, vec[0], vec[1]);
    }

    vector<bool> vis(n, false);
    vector<bool> path(n, false);

    for (int i = 0; i < n;i++)
    {
        if(!vis[i])
        {
            if(!kans_dfs(graph, vis, path, i))
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