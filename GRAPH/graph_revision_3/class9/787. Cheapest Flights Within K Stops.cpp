#include <bits/stdc++.h>
using namespace std;

int bellManFord(vector<vector<int>> &edges, int src, int dst, int V, int k)
{
    vector<int> prev(V, 1e7);
    vector<int> curr(V, 1e7);
    prev[src] = curr[src] = 0;
    int cnt = k + 1;
    while (cnt--)
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
        // if (V == 0 and updateDone)
        // {
        //     cout << "neagative weight cycle is +snt ans can not be calculated";
        // }
        if (!updateDone)
        {
            break;
        }
        for (int i = 0; i < prev.size(); i++)
        {
            prev[i] = curr[i];
            cout << curr[i] << " ";
        }
        cout << endl;
    }
    if (curr[dst] == 1e7)
    {
        return -1;
    }
    return curr[dst];
}


int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    return bellManFord(flights, src, dst, n, k);
}

int main()
{
    return 0;
}