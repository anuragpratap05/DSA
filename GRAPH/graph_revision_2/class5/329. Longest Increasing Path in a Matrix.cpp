#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
void addedge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> indegree(m * n, 0);
    vector<vector<int>> graph(m*n, vector<int>());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (auto &vec : dir)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and matrix[r][c] > matrix[i][j])
                {
                    indegree[(i * m) + j]++;
                    addedge(graph, (i * m) + j, (r * m) + c);
                }
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int l = 0;

    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int rn = q.front();
            q.pop();

            for(int e:graph[rn])
            {
                if(--indegree[e]==0)
                {
                    q.push(e);
                }
            }
        }
        l++;
    }
    return l;
}

int main()
{
    return 0;
}