#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &maps, vector<vector<int>> &routes, int src, int dst, int n)
{
    queue<int> q;
    vector<bool> busNo(n, false);
    vector<bool> busStop(1e6, false);
    q.push(src);
    busStop[src] = true;
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            if (vtx == dst)
            {
                return level + 1;
            }
            for (int bus : maps[vtx])
            {
                if (!busNo[bus])
                {
                    busNo[bus] = true;
                    for (int stop : routes[bus])
                    {
                        if (!busStop[stop])
                        {
                            busStop[stop] = true;
                            q.push(stop);
                        }
                    }
                }
            }
        }
        level++;
    }
    return -1;
}

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    vector<vector<int>> maps(1e6, vector<int>());
    int n = routes.size();
    for (int i = 0; i < n; i++)
    {
        for (int e : routes[i])
        {
            maps[e].push_back(i);
        }
    }
    return bfs(maps, routes, source, target, n);
}

int main()
{
    return 0;
}