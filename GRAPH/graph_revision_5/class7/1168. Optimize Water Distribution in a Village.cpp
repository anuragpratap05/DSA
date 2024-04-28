#include <bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> size;

int find(int i)
{
    if (par[i] == i)
        return i;
    return par[i] = find(par[i]);
}

void unite(int p1, int p2)
{
    int maxSize = 0;
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
int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i <= n; i++)
    {
        par.push_back(i);
        size.push_back(1);
    }
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }

    sort(pipes.begin(), pipes.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    int cost = 0;

    for (vector<int> &edge : pipes)
    {
        int u = edge[0];
        int v = edge[1];
        int amt = edge[2];

        int p1 = find(u);
        int p2 = find(v);

        if (p1 != p2)
        {
            cost += amt;
            unite(p1, p2);
        }
    }
    return cost;
}

int main()
{
    return 0;
}