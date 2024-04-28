#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int fresh = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                fresh++;
            }
            else if (grid[i][j] == 2)
            {
                q.push(i * m + j);
            }
        }
    }
    if (fresh == 0)
    {
        return 0;
    }
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int idx = q.front();
            q.pop();
            int i = idx / m;
            int j = idx % m;
            for (vector<int> &vec : dir)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
                {
                    grid[r][c] = 0;
                    fresh--;
                    q.push(r * m + c);
                    if (fresh == 0)
                    {
                        return level + 1;
                    }
                }
            }
        }
        level++;
    }
    return -1;
}

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.

int main()
{
    return 0;
}