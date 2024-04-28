#include <bits/stdc++.h>
using namespace std;

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> indegree(n, vector<int>(m, 0));
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (vector<int> &vec : dirs)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and matrix[i][j] > matrix[r][c])
                {
                    indegree[i][j]++;
                }
            }
            if (indegree[i][j] == 0)
            {
                q.push(i * m + j);
            }
        }
    }
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int idx = q.front();
            int i = idx / m;
            int j = idx % m;
            for (vector<int> &vec : dirs)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and matrix[r][c] > matrix[i][j])
                {
                    if (--indegree[r][c] == 0)
                    {
                        q.push(r * m + c);
                    }
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