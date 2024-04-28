#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> moves = {"u", "r", "d", "l"};

string dfs(vector<vector<int>> &grid, int i, int j)
{
    grid[i][j] = 0;
    string path = "";
    for (int itr = 0; itr < dirs.size(); itr++)
    {
        vector<int> &vec = dirs[itr];
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < grid.size() and c < grid[0].size() and grid[r][c] == 1)
        {
            path += moves[itr];
            path += dfs(grid, r, c);
        }
    }
    path += "b";
    return path;
}
int numDistinctIslands(vector<vector<int>> &grid)
{
    unordered_set<string> s;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {

                string path = dfs(grid, i, j);
                s.insert(path);
            }
        }
    }
    return s.size();
}

int main()
{
    return 0;
}