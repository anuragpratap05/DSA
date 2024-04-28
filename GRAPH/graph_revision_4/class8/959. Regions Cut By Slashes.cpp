#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> size;

int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }
    return par[i] = find(par[i]);
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

void unionFind(vector<vector<int>> &edges, int n)
{
    par.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    for (vector<int> &vec : edges)
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

int regionsBySlashes(vector<string> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    n += 1;
    m += 1;
    par.resize(n * m);
    size.resize(n * m);
    for (int i = 0; i < n * m; i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                par[i * m + j] = 0;
                size[0]++;
            }
        }
    }
    int region = 1;
    for (int i = 0; i < grid.size(); i++)
    {
        string str = grid[i];
        for (int j = 0; j < str.size(); j++)
        {
            if (grid[i][j] == '/')
            {
                int p1 = find(i * m + (j + 1));
                int p2 = find((i + 1) * m + j);
                if (p1 != p2)
                {
                    unite(p1, p2);
                }
                else
                {
                    region++;
                }
            }
            else if (grid[i][j] == '\\')
            {
                int p1 = find(i * m + j);
                int p2 = find((i + 1) * m + (j + 1));
                if (p1 != p2)
                {
                    unite(p1, p2);
                }
                else
                {
                    region++;
                }
            }
        }
    }
    return region;
}

int main()
{
    return 0;
}