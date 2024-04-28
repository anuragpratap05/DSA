#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<int> q;
    int freshCnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push((i * m) + j);
                // grid[i][j] = 0;
            }
            else if (grid[i][j] == 1)
            {
                freshCnt++;
            }
        }
    }

    if (freshCnt == 0)
    {
        return 0;
    }
    int time = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int idx = q.front();
            q.pop();
            int i = idx / m;
            int j = idx % m;
            for (vector<int> &vec : dirs)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
                {
                    freshCnt--;
                    if (freshCnt == 0)
                    {
                        return time + 1;
                    }
                    grid[r][c] = 0;
                    q.push((r * m) + c);
                }
            }
        }
        time++;
    }
    // if (freshCnt == 0)
    // {

    //     return time;
    // }
    return -1;
}

int main()
{
    return 0;
}