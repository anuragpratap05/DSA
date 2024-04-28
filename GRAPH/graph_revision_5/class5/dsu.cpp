#include <bits/stdc++.h>
using namespace std;

vector<int> size;
vector<int> par;

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
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        size[i] = 1;
    }

    for (vector<int> &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int p1 = find(u);
        int p2 = find(v);
        if (p1 != p2)
        {
            unite(p1, p2);
        }
    }
}

int main()
{
    return 0;
}