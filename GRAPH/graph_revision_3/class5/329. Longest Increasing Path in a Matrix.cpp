#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> indegree(n * m, 0);
    vector<vector<int>> graph(n * m, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (vector<int> &vec : dir)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and matrix[r][c] > matrix[i][j])
                {
                    addEdge(graph, i * m + j, r * m + c);
                    indegree[r * m + c]++;
                }
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int level = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int idx = q.front();
            q.pop();
            int r = idx / m;
            int c = idx % m;
            for (int e : graph[idx])
            {
                indegree[e]--;
                if (indegree[e] == 0)
                {
                    q.push(e);
                }
            }
        }
        level++;
    }
    return level;
}
int main()
{
    return 0;
}