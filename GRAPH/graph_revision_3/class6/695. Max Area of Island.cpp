#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{0, 1}, {1, 0}};
vector<int> par;
vector<int> size;

int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }

    return par[i] = find(par[i]);
    // return par[i];
}

void unite(int p1, int p2)
{
    if (size[p1] > size[p2])
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }
    else
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
}

void unionFind(int V, vector<vector<int>> &connections)
{
    par.resize(V);
    size.resize(V, 1);
    for (int i = 0; i < V; i++)
    {
        par[i] = i;
    }
    for (vector<int> &vec : connections)
    {
        int u = vec[0];
        int v = vec[1];

        int p1 = find(u);
        int p2 = find(v);

        if (p1 != p2)
        {
            unite(p1, p2);
        }
    }
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> connections;
    bool oneP = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                oneP = true;

                for (vector<int> &vec : dir)
                {
                    int r = i + vec[0];
                    int c = j + vec[1];
                    if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
                    {
                        connections.push_back({i * m + j, r * m + c});
                    }
                }
            }
        }
    }
    if (!oneP)
    {
        return 0;
    }

    unionFind(n * m, connections);
    int maxi = 0;
    for (int e : size)
    {
        maxi = max(maxi, e);
    }
    return maxi;
}
int main()
{
    return 0;
}