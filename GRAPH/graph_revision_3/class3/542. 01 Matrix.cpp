#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    queue<int> q;
    vector<vector<int>> ans(n, vector<int>(m, 0));
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
    int level = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int idx = q.front();
            q.pop();
            int i = idx / m;
            int j = idx % m;
            for (vector<int> &vec : dir)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and mat[r][c] == 1)
                {
                    mat[r][c] = 0;
                    ans[r][c] = level;
                    q.push(r * m + c);
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