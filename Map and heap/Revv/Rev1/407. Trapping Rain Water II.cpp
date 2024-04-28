#include <bits/stdc++.h>
using namespace std;

int trapRainWater(vector<vector<int>> &heightMap)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int n = heightMap.size();
    int m = heightMap[0].size();

    vector<vector<int>> vis(n, vector<int>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                pq.push({heightMap[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    int water = 0;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();

        int minBoundaryEle = vec[0];
        int i = vec[1];
        int j = vec[2];

        for (vector<int> &d : dirs)
        {
            int r = i + d[0];
            int c = j + d[1];

            if (r >= 0 and c >= 0 and r < n and c < m and !vis[r][c])
            {
                if (heightMap[r][c] < minBoundaryEle)
                {
                    water += (minBoundaryEle - heightMap[r][c]);
                    heightMap[r][c] = minBoundaryEle;
                }
                pq.push({heightMap[r][c], r, c});
                vis[r][c] = true;
            }
        }
        
    }
    return water;
}

int main()
{
    return 0;
}