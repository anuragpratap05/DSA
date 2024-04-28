#include <bits/stdc++.h>
using namespace std;

int BellmanFoord(vector<vector<int>> &edges, int n, int src, int k, int dst)
{
    vector<int> curr(n, 1e7);
    vector<int> prev(n, 1e7);
    prev[src] = curr[src] = 0;
    int cnt = k + 1;
    while (cnt--)
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
        for (int i = 0; i < n; i++)
        {
            prev[i] = curr[i];
        }
    }
    if (curr[dst] == 1e7)
    {
        return -1;
    }
    return curr[dst];
}
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    return BellmanFoord(flights, n, src, k, dst);
}
int main()
{
    return 0;
}