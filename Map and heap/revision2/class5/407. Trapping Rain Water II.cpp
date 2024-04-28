#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int trapRainWater(vector<vector<int>> &heightMap)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int n = heightMap.size();
    int m = heightMap[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                pq.push({heightMap[i][j], (i * m) + j});
                vis[i][j] = true;
            }
        }
    }
    int ans = 0;
    while (!pq.empty())
    {
        int minBoundryEleIdx = pq.top()[1];
        int i = minBoundryEleIdx / m;
        int j = minBoundryEleIdx % m;
        int minBoundryEle = pq.top()[0];
        pq.pop();
        for (vector<int> &dir : dirs)
        {
            int r = i + dir[0];
            int c = j + dir[1];
            if (r >= 0 and c >= 0 and r < n and c < m and !vis[r][c])
            {
                if (heightMap[r][c] < minBoundryEle)
                {
                    ans += (minBoundryEle - heightMap[r][c]);
                    pq.push({minBoundryEle, r * m + c});
                    heightMap[r][c] = minBoundryEle;
                    vis[r][c] = true;
                }
                else
                {
                    pq.push({heightMap[r][c], r * m + c});
                    vis[r][c] = true;
                }
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}