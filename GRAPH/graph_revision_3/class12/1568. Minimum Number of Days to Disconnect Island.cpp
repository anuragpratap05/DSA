#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int x = 0;
void dfs(vector<vector<int>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    grid[i][j] = 0;
    for (vector<int> &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
        {
            dfs(grid, r, c);
        }
    }
}

bool twoComponents(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                cnt++;
                if (cnt > 1)
                {
                    return true;
                }
                dfs(grid, i, j);
            }
        }
    }
    return false;
}

bool articulationPointHelp(vector<vector<int>> &grid, vector<vector<int>> &disc, vector<vector<int>> &low, vector<vector<bool>> &vis, int i, int j, int parI, int parJ, vector<vector<int>> &aP)
{
    int n = grid.size();
    int m = grid[0].size();
    disc[i][j] = low[i][j] = x;
    x++;
    vis[i][j] = true;
    bool res = false;
    for (auto &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m)
        {
            if (!vis[r][c])
            {
                res = res || articulationPointHelp(grid, disc, low, vis, r, c, i, j, aP);
                if (disc[i][j] <= low[r][c])
                {
                    aP[i][j]++;
                    if (aP[i][j] == 1)
                    {
                        res = true;
                    }

                }
                low[i][j] = min(low[i][j], low[r][c]);
            }
            else if (parI != r or parJ != c)
            {
                low[i][j] = min(low[i][j], disc[r][c]);
            }
        }
    }
    // disc[i][j] = low[i][j] = 0;
    // x++;
    // vis[i][j] = false;
    return res;
}

int minDays(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> disc(n, vector<int>(m, 0));
    vector<vector<int>> low(n, vector<int>(m, 0));
    vector<vector<int>> aP(n, vector<int>(m, 0));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                aP[i][j] = -1;
                bool ans = articulationPointHelp(grid, disc, low, vis, i, j, -1, -1, aP);
                if (ans)
                {
                    return 1;
                }
                else
                {
                    if (twoComponents(grid))
                    {
                        return 0;
                    }
                    return 2;
                }
                // grid[i][j] = 0;
                // x = 0;
                // cnt++;
                // vis.clear();
                // disc.clear();
                // low.clear();
                // aP.clear();
                // vis.resize(n, vector<bool>(m, false));
                // disc.resize(n, vector<int>(m, 0));
                // low.resize(n, vector<int>(m, 0));
                // aP.resize(n, vector<int>(m, 0));
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}