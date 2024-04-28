#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(vector<vector<int>> &grid, int i, int j)
{
    grid[i][j] = 0;
    int myArea = 0;
    for (vector<int> &vec : dirs)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < grid.size() and c < grid[0].size() and grid[r][c] == 1)
        {
            myArea += dfs(grid, r, c);
        }
    }
    return myArea + 1;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {

                maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
    }
    return maxArea;
}

int main()
{
    return 0;
}