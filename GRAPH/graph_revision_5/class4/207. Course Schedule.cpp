#include <bits/stdc++.h>
using namespace std;

bool canFinish2(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    for (vector<int> &vec : prerequisites)
    {
        int u = vec[0];
        int v = vec[1];
        indegree[v]++;
        graph[u].push_back(v);
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            cnt++;
            for (int e : graph[vtx])
            {
                if (--indegree[e] == 0)
                {
                    q.push(e);
                }
            }
        }
    }
    return numCourses == cnt;
}

bool topologiclDfsPossible(vector<vector<int>> &graph, int src, vector<bool> &vis, vector<bool> &path)
{
    vis[src] = path[src] = true;
    for (int e : graph[src])
    {
        if (!vis[e])
        {
            bool ans = topologiclDfsPossible(graph, e, vis, path);
            if (!ans)
            {
                return false;
            }
        }
        else if (path[e])
        {
            return false;
        }
    }
    path[src] = false;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>());
    for (vector<int> &vec : prerequisites)
    {
        int u = vec[0];
        int v = vec[1];
        graph[u].push_back(v);
    }
    vector<bool> vis(numCourses, false);
    vector<bool> path(numCourses, false);

    for (int i = 0; i < vis.size(); i++)
    {
        if (!vis[i])
        {
            bool isPossible = topologiclDfsPossible(graph, i, vis, path);
            if (!isPossible)
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