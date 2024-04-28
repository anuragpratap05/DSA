#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(vector<vector<int>> &grid, int i, int j)
{
    grid[i][j] = 0;
    int size = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (auto &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];

        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
        {
           size+= dfs(grid, r, c);
        }
    }
    return size + 1;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {

                ans = max(ans, dfs(grid, i, j));
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}