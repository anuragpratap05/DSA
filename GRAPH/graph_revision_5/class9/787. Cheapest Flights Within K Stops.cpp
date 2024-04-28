#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{

    vector<int> prev(n, 1e7);
    prev[src] = 0;
    vector<int> curr(prev);
    k += 1;
    while (k--)
    {
        bool updated = false;
        for (vector<int> &edge : flights)
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
                updated = true;
                curr[v] = prev[u] + w;
            }
        }

        for (int i = 0; i < curr.size(); i++)
        {
            prev[i] = curr[i];
        }
        if (!updated)
        {
            break;
        }
    }
    if (curr[dst] == 1e7)
    {
        return -1;
    }
    return curr[dst];
}
int main()
{
    return 0;
}