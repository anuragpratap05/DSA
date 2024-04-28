#include <bits/stdc++.h>
using namespace std;
string s;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> dirs = {"U", "R", "D", "L"};

void dfs(vector<vector<int>> &grid, int i, int j)
{
    grid[i][j] = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int d = 0; d < dir.size(); d++)
    {
        int r = i + dir[d][0];
        int c = j + dir[d][1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
        {
            s += dirs[d];
            dfs(grid, r, c);
        }
    }
    s += "b";
}

int numberofDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    unordered_map<string, bool> ma;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                s = "";
                dfs(grid, i, j);
                if(s!="" and ma.find(s)==ma.end())
                {
                    ma[s] = true;
                }
            }
        }
    }
    return ma.size();
}

int main()
{
    return 0;
}