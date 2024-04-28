#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<vector<int>> &grid, int i, int j)
{
    grid[i][j] = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (vector<int> &vec : dirs)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
        {
            dfs(grid, r, c);
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}