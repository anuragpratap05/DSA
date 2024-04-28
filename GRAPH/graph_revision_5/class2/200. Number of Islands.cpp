#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<vector<char>> &grid, int i, int j)
{
    grid[i][j] = '0';
    for(vector<int>& vec:dirs)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if(r>=0 and c>=0 and r<grid.size() and c<grid[0].size() and grid[r][c]=='1')
        {
            dfs(grid, r, c);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size();j++)
        {
            if(grid[i][j]=='1')
            {
                cnt++;
                dfs(grid, i, j);
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}