#include<bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> size;

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

vector<int> union_find(vector<vector<int>> &edges, int V)
{
    size.resize(V, 1);
    par.resize(V, 0);
    for (int i = 0; i < V; i++)
    {
        par[i] = i;
    }

    for (auto vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        int p1 = find(u);
        int p2 = find(v);

        if (p1 != p2)
        {
            unite(p1, p2);
        }
        else
        {
            return vec;
        }
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    return union_find(edges ,n+ 1);
}

int main()
{
    return 0;
}