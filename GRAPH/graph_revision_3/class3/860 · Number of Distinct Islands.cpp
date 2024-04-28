#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> strArr = {"U", "R", "D", "L"};

string dfs(vector<vector<int>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    grid[i][j] = 0;
    string ans = "";
    for (int itr = 0; itr < dir.size(); itr++)
    {
        int r = i + dir[itr][0];
        int c = j + dir[itr][1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
        {
            ans += strArr[itr];
            ans += dfs(grid, r, c);
        }
    }
    ans += "B";
    return ans;
}

int numberofDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    unordered_set<string> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {

                string str = dfs(grid, i, j);
                s.insert(str);
            }
        }
    }
    return s.size();
}
int main()
{
    return 0;
}