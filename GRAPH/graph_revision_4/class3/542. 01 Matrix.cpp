#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
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
            q.pop();
            int i = idx / m;
            int j = idx % m;
            ans[i][j] = level;
            for (vector<int> &vec : dirs)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and mat[r][c] == 1)
                {
                    q.push(r * m + c);
                    mat[r][c] = 0;
                }
            }
        }
        level++;
    }
    return ans;
}

int main()
{
    return 0;
}