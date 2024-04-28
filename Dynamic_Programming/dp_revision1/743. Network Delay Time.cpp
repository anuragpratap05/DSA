#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int v, w;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addEdge(vector<vector<Edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
}

class comp
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return b[1] < a[1];
    }
};

int dijkstra(vector<vector<Edge>> &graph, int src, int n)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<bool> vis(n + 1, false);

    int cnt = n;

    pq.push({src, 0});

    int maxtime = 0;

    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();

        int vtx = vec[0];
        int wsf = vec[1];
        if (vis[vtx])
            continue;

        vis[vtx] = true;
        cnt--;
        maxtime = max(maxtime, wsf);

        for (Edge e : graph[vtx])
        {
            if (!vis[e.v])
            {
                pq.push({e.v, wsf + e.w});
            }
        }
    }
    return cnt == 0 ? maxtime : -1;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<Edge>> graph(n + 1, vector<Edge>());

    for (vector<int> &edge : times)
    {
        addEdge(graph, edge[0], edge[1], edge[2]);
    }

    return dijkstra(graph, k, n);
}

int main()
{
    return 0;
}