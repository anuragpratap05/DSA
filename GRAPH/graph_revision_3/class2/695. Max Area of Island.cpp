#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfsArea(vector<vector<int>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    grid[i][j] = 0;
    int area = 0;
    for (vector<int> &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
        {
            area += dfsArea(grid, r, c);
        }
    }
    return area + 1;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int area = dfsArea(grid, i, j);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}

int main()
{
    return 0;
}