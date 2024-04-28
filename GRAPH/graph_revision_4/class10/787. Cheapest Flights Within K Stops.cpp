#include <bits/stdc++.h>
using namespace std;
int bellmanFord(vector<vector<int>> &edges, int vtxs, int src, int dst, int k)
{
    vector<int> prev(vtxs, 1e7);
    vector<int> curr(vtxs, 1e7);
    prev[src] = curr[src] = 0;
    k += 1;
    while (k--)
    {
        bool isUpdated = false;
        for (vector<int> &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            if (prev[u] + w < curr[v])
            {

                isUpdated = true;
                curr[v] = prev[u] + w;
            }
        }
        for (int i = 0; i < vtxs; i++)
        {
            prev[i] = curr[i];
        }
        if (!isUpdated)
        {
            // cout << "if any any point no update is done then in future there will be no updates";
            break;
        }
    }

    return (curr[dst] == 1e7 ? -1 : curr[dst]);
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    return bellmanFord(flights, n, src, dst, k);
}

int main()
{
    return 0;
}