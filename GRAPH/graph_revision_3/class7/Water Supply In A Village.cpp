#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });
}
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

int unionfind(vector<vector<int>> &pipes, int n)
{
    par.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    int ans = 0;
    for (vector<int> &vec : pipes)
    {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];
        int p1 = find(u);
        int p2 = find(v);
        if (p1 != p2)
        {
            unite(p1, p2);
            ans += w;
        }
    }
    return ans;
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes)
{
    for (int i = 0; i < n; i++)
    {
        pipes.push_back({0, i + 1, wells[i]});
    }
    sortArray(pipes);
    return unionfind(pipes, n);
}

int main()
{
    return 0;
}