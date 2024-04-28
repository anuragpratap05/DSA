#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}
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

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
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
    reverse(ans.begin(), ans.end());
    if(ans.size()!=numCourses)
    {
        return {};
    }
    return ans;
}

int main()
{
    return 0;
}