#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

// Method 3 : using dfs
bool dfsCycleDetector(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &path, int src, vector<int> &vec)
{
    vis[src] = true;
    path[src] = true;
    for (int e : graph[src])
    {
        if (path[e])
        {
            return true;
        }
        if (!vis[e])
        {
            bool ans = dfsCycleDetector(graph, vis, path, e, vec);
            if (ans)
            {
                return true;
            }
        }
    }
    path[src] = false;
    vec.push_back(src);
    return false;
}
bool canFinish3(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> grpah(numCourses, vector<int>());
    vector<bool> vis(numCourses, false);
    vector<bool> path(numCourses, false);
    for (vector<int> &vec : prerequisites)
    {
        addEdge(grpah, vec[0], vec[1]);
    }
    vector<int> vec;
    for (int i = 0; i < numCourses; i++)
    {
        if (!vis[i])
        {
            if (dfsCycleDetector(grpah, vis, path, i, vec))
            {
                return false;
            }
        }
    }
    return true;
}

//===============================================================================

// Method2 // glt hai bfs cycle detector unidirected graph me cycle detect nhi kr paega, testcase: 0->1  1->2 2->1 1->0
bool bfsCycleDetector(vector<vector<int>> &graph, vector<bool> &vis, int src)
{
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            if (vis[vtx])
            {
                // cout << "cycle present";
                return true;
            }
            vis[vtx] = true;
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    q.push(e);
                }
            }
        }
    }
    return false;
}
bool canFinish2(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> grpah(numCourses, vector<int>());
    vector<bool> vis(numCourses, false);
    for (vector<int> &vec : prerequisites)
    {
        addEdge(grpah, vec[0], vec[1]);
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (!vis[i])
        {
            if (bfsCycleDetector(grpah, vis, i))
            {
                return false;
            }
        }
    }
    return true;
}

//==============================================================================
void bfs(vector<int> &indegree, vector<vector<int>> &grpah, vector<int> &ans)
{
    int n = grpah.size();
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            ans.push_back(vtx);
            for (int e : grpah[vtx])
            {
                indegree[e]--;
                if (indegree[e] == 0)
                {
                    q.push(e);
                }
            }
        }
    }
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> grpah(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    for (vector<int> &vec : prerequisites)
    {
        addEdge(grpah, vec[0], vec[1]);
        indegree[vec[1]]++;
    }
    vector<int> ans;
    bfs(indegree, grpah, ans);
    return ans.size() == numCourses;
}

int main()
{
    return 0;
}