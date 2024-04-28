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

vector<int> unionFind(int V, vector<vector<int>> &connections)
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
        else
        {
            return vec;
        }
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int V = edges.size();
    return unionFind(V, edges);
}

int main()
{
    return 0;
}