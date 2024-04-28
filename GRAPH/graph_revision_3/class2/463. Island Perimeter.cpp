#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 0}};

int islandPerimeter(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int box = 0;
    int conn = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                box++;
                for (vector<int> &vec : dir)
                {
                    int r = i + vec[0];
                    int c = j + vec[1];
                    if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
                    {
                        conn++;
                    }
                }
            }
        }
    }
    int ans = 4 * box - (2 * conn);
    return ans;
}

int main()
{
    return 0;
}