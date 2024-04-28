#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> size;
vector<vector<int>> dir = {{0, 1}, {1, 0}};

void unite(int p1, int p2)
{
    if (size[p1] < size[p2])
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }
}

int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }

    par[i] = find(par[i]);

    return par[i];
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    size.resize(n * m, 1);
    par.resize(n * m, 0);
    for (int i = 0; i < n * m; i++)
    {
        par[i] = i;
    }
    int oc = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                oc++;
                for (auto &vec : dir)
                {
                    int r = i + vec[0];
                    int c = j + vec[1];

                    if (r < n and c < m and grid[r][c] == 1)
                    {
                        int p1 = find((i * m) + j);
                        int p2 = find((r * m) + c);

                        if (p1 != p2)
                        {
                            unite(p1, p2);
                        }
                    }
                }
            }
        }
    }
    if (oc == 0)
    {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n * m; i++)
    {
        ans = max(ans, size[i]);
    }
    return ans;
}

int main()
{
    return 0;
}