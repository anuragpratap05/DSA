#include <bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<int>> &edges, int vtxs, int src)
{
    vector<int> prev(vtxs, 1e7);
    vector<int> curr(vtxs, 1e7);
    prev[src] = curr[src] = 0;
    while (vtxs--)
    {
        bool isUpdated = false;
        for (vector<int> &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            if (prev[u] + w < curr[v])
            {
                if (vtxs == 1)
                {
                    cout << " answer is not possible , a -ve weighted cycle is present in graph";
                    break;
                }
                isUpdated = true;
                curr[v] = prev[u] + w;
            }
            for (int i = 0; i < vtxs; i++)
            {
                prev[i] = curr[i];
            }
        }
        if (!isUpdated)
        {
            cout << "if any any point no update is done then in future there will be no updates";
            break;
        }
    }
}

int main()
{
    return 0;
}