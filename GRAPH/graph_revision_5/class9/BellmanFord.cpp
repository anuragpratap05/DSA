#include <bits/stdc++.h>
using namespace std;

void bellManFord(vector<vector<int>> &edges, int vtxs, int src)
{
    vector<int> prev(vtxs, 1e7);
    prev[src] = 0;
    vector<int> curr(prev);

    while (vtxs--)
    {
        for (vector<int> &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            if (prev[u] == 1e7)
            {
                continue;
            }
            if (prev[u] + w < curr[v])
            {
                curr[v] = prev[u] + w;
            }
        }
        for (int i = 1; i < curr.size(); i++)
        {
            prev[i] = curr[i];
            cout << curr[i] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edges = {{1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 5, 2}, {2, 4, 2}, {5, 4, -3}, {4, 2, -1}, {4, 3, 5}};

    bellManFord(edges, 6, 1);
    return 0;
}