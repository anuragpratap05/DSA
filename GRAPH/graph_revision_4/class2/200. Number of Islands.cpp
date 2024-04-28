#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<vector<char>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    grid[i][j] = '0';
    for (vector<int> &vec : dirs)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == '1')
        {
            dfs(grid, r, c);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int compo = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                compo++;
                dfs(grid, i, j);
            }
        }
    }
    return compo;
}

int main()
{
    return 0;
}