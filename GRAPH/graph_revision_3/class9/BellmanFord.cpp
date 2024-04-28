#include <bits/stdc++.h>
using namespace std;

void bellManFord(vector<vector<int>> &edges, int src, int V)
{
    vector<int> prev(V+1, 1e7);
    vector<int> curr(V+1, 1e7);
    prev[src] = curr[src] = 0;
    while (V--)
    {
        bool updateDone = false;
        for (auto &vec : edges)
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
                updateDone = true;
                curr[v] = prev[u] + w;
            }
        }
        if (V == 0 and updateDone)
        {
            cout << "neagative weight cycle is +snt ans can not be calculated" << endl;
        }
        if (!updateDone)
        {
            cout << "breaked>>>>";
            break;
        }
        for (int i = 0; i < prev.size(); i++)
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