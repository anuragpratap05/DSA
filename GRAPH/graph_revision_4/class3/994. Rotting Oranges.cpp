#include <bits/stdc++.h>
using namespace std;
void bfsoptimized(vector<vector<int>> &graph, int src)
{

    vector<bool> vis(graph.size(), false);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();

            cout << "visited " << vtx << " at level " << level << endl;
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    q.push(e);
                    vis[e] = true;
                }
            }
        }
        level++;
    }
}

int orangesRotting(vector<vector<int>> &grid)
{
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int n = grid.size();
    int m = grid[0].size();
    int freshCnt = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                freshCnt++;
            }
            else if (grid[i][j] == 2)
            {
                q.push(i * m + j);
            }
        }
    }
    if (freshCnt == 0)
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
            for (vector<int> &vec : dirs)
            {
                int r = i + vec[0];
                int c = j + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
                {
                    q.push(r * m + c);
                    grid[r][c] = 0;
                    freshCnt--;
                    if (freshCnt == 0)
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

int main()
{
    return 0;
}