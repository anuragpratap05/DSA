#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void numIslandsDfs(vector<vector<char>> &grid, int i, int j)
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
            numIslandsDfs(grid, r, c);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                numIslandsDfs(grid, i, j);
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