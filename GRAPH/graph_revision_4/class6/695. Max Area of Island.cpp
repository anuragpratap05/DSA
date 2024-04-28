#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> size;
vector<vector<int>> dirs = {{0, 1}, {1, 0}};
int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }
    return par[i] = find(par[i]);
}

int unite(int p1, int p2)
{
    int maxSize = 0;
    if (size[p1] > size[p2])
    {
        par[p2] = p1;
        size[p1] += size[p2];
        maxSize = size[p1];
    }
    else
    {
        par[p1] = p2;
        size[p2] += size[p1];
        maxSize = size[p2];
    }
    return maxSize;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    par.resize(n * m);
    size.resize(n * m);
    for (int i = 0; i < n * m; i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    bool onePresent = false;
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                onePresent = true;
                for (vector<int> &vec : dirs)
                {
                    int r = i + vec[0];
                    int c = j + vec[1];
                    if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
                    {
                        int p1 = find(i * m + j);
                        int p2 = find(r * m + c);
                        if (p1 != p2)
                        {
                            maxSize = max(maxSize, unite(p1, p2));
                        }
                    }
                }
            }
        }
    }
    if (maxSize == 0 and onePresent)
    {
        return 1;
    }
    return maxSize;
}

int main()
{
    return 0;
}