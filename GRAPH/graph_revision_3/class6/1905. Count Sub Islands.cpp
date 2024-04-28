#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
{
    int n = grid2.size();
    int m = grid2[0].size();
    grid2[i][j] = 0;
    bool ans = grid1[i][j] == 1;
    for (vector<int> &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid2[r][c] == 1)
        {
            ans = dfs(grid1, grid2, r, c) && ans;
        }
    }
    return ans;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int n = grid2.size();
    int m = grid2[0].size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid2[i][j] == 1)
            {
                if (dfs(grid1, grid2, i, j))
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}