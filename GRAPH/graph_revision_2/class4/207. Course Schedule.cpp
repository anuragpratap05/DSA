#include <bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}

vector<int> kans_mama_algo(vector<vector<int>> &graph, vector<int> &indegree)
{
    queue<int> q;
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int topo_velel = 0;
    vector<int> ans;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int rn = q.front();
            q.pop();
            ans.push_back(rn);

            for (int e : graph[rn])
            {
                if (--indegree[e] == 0)
                {
                    q.push(e);
                }
            }
        }
        topo_velel++;
    }
    return ans;
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

    vector<int> ans = kans_mama_algo(graph, indegree);
    return ans.size() == n;
}

int main()
{
    return 0;
}