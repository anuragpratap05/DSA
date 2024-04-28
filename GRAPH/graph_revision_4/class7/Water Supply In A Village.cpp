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

int unionFind(vector<vector<int>> &edges, int n)
{
    par.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    int ans = 0;
    for (vector<int> &vec : edges)
    {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];
        int p1 = find(u);
        int p2 = find(v);
        if (p1 != p2)
        {
            ans += w;
            unite(p1, p2);
        }
    }
    return ans;
}
void sortArray(vector<vector<int>> &vec)
{
    sort(vec.begin(), vec.end(), [](vector<int> &a, vector<int> &b)
         {
             return a[2] < b[2]; // this - other ->default behavior
             return b[2] < a[2]; // other - this -> rev of def behaviour
         });
}
int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i < wells.size(); i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }
    sortArray(pipes);
    return unionFind(pipes, n + 1);
}

int main()
{
    return 0;
}