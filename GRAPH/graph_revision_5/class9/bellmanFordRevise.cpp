#include <bits/stdc++.h>
using namespace std;

void bellManFord(vector<vector<int>> &edges, int src, int Vtxs)
{
    vector<int> prev(Vtxs + 1, 1e7);
    prev[src] = 0;
    vector<int> curr(prev);
    bool negativeCyclePresent = false;

    while (Vtxs--)
    {
        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (prev[u] == 1e7)
            {
                continue;
            }
            if (prev[u] + w < curr[v])
            {
                if (Vtxs == 0)
                {
                    negativeCyclePresent = true;
                    // cout << "negative cycle present" << endl;
                    // break;
                }
                curr[v] = prev[u] + w;
            }
        }
        if (negativeCyclePresent)
        {
            cout << "negative cycle present" << endl;
        }
        for (int i = 1; i < curr.size(); i++)
        {
            prev[i] = curr[i];
            cout << curr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edges = {{1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 5, 2}, {2, 4, 2}, {5, 4, -3}, {4, 2, -1}, {4, 3, 5}};

    bellManFord(edges, 1, 5);
    return 0;
}