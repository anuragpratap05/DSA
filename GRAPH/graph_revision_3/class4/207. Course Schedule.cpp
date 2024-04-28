#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}
bool hasCycle(vector<vector<int>> &graph, int src, vector<bool> &vis, vector<bool> &path)
{
    vis[src] = true;
    path[src] = true;
    bool ans = false;
    for (int e : graph[src])
    {
        if (path[e])
        {
            return true;
        }
        if (!vis[e])
            ans = ans || hasCycle(graph, e, vis, path);
    }
    path[src] = false;
    return ans;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>());
    for (vector<int> &vec : prerequisites)
    {
        addEdge(graph, vec[0], vec[1]);
    }

    vector<bool> vis(numCourses, false);
    vector<bool> path(numCourses, false);
    for (int i = 0; i < numCourses; i++)
    {
        if (!vis[i])
        {
            bool cyclePresrent = hasCycle(graph, i, vis, path);
            if (cyclePresrent)
            {
                return false;
            }
        }
    }
    return true;
}

bool canFinish2(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> graph(numCourses, vector<int>());

    for (vector<int> &vec : prerequisites)
    {
        indegree[vec[1]]++;
        addEdge(graph, vec[0], vec[1]);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int idx = q.front();
            q.pop();
            ans.push_back(idx);
            for (int e : graph[idx])
            {
                indegree[e]--;
                if (indegree[e] == 0)
                {
                    q.push(e);
                }
            }
        }
    }
    return ans.size() == numCourses;
}

int main()
{
    return 0;
}