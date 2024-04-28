#include<bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> size;

void unite(int p1,int p2)
{
    if(size[p1]<size[p2])
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
    if(par[i]==i)
    {
        return i;
    }

    par[i] = find(par[i]);

    return par[i];
}

void union_find(vector<vector<int>>& edges,int V)
{
    size.resize(V, 1);
    par.resize(V, 0);
    for (int i = 0; i < V; i++)
    {
        par[i] = i;
    }

    for(auto vec:edges)
    {
        int u = vec[0];
        int v = vec[1];
        int p1 = find(u);
        int p2 = find(v);

        if(p1!=p2)
        {
            unite(p1, p2);
        }
    }
}

int main()
{
    int V = 9;

    vector<vector<int>> edges = {{0, 3}, {0, 1}, {2, 3}, {1, 2}, {2, 7}, {2, 8}, {7, 8}, {3, 4}, {4, 5}, {4, 6}, {4, 6}, {5, 6}, {2,7},{2,8},{7,8}};

    union_find(edges, V);

    return 0;
}