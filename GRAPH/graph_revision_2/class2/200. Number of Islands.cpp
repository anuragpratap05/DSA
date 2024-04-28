#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


void dfs(vector<vector<char>> &grid, int i, int j)
{
    grid[i][j] = '0';
    int n = grid.size();
    int m = grid[0].size();
    for (auto &vec : dir)
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
    int co = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                co++;
                dfs(grid, i, j);
            }
        }
    }
    return co;
}

int main()
{
    vector<vector<string>> grid = {
        {"1", "1", "0", "0", "0"},
        {"1", "1", "0", "0", "0"},
        {"0", "0", "1", "0", "0"},
        {"0", "0", "0", "1", "1"}};
    return 0;
}