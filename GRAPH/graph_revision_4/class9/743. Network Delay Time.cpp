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
        return b[1] < a[1]; // this-other
    }
};
int DijkstraOptimized(vector<vector<Edge>> &graph, int src, int n)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    pq.push({src, 0});
    int maxTime = 0;
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;
    int cnt = n;

    while (!pq.empty())
    {
        int size = pq.size();
        while (size--)
        {
            vector<int> vec = pq.top();
            pq.pop();
            int vtx = vec[0];
            int wsf = vec[1];
            if (dist[vtx] < wsf)
            {
                continue;
            }
            maxTime = max(maxTime, wsf);
            for (Edge e : graph[vtx])
            {
                if (wsf + e.w < dist[e.v])
                {
                    dist[e.v] = wsf + e.w;
                    pq.push({e.v, wsf + e.w});
                }
            }
        }
    }
    if (cnt == 0)
        return maxTime;
    return -1;
}

int Dijkstra(vector<vector<Edge>> &graph, int src, int n)
{
    //{src,wsf}
    int cnt = n;
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<bool> vis(n + 1, false);
    int maxTime = 0;
    pq.push({src, 0});
    while (!pq.empty())
    {
        int size = pq.size();
        while (size--)
        {
            vector<int> vec = pq.top();
            pq.pop();
            int vtx = vec[0];
            int wsf = vec[1];
            if (vis[vtx])
            {
                continue;
            }
            vis[vtx] = true;
            cnt--;
            maxTime = max(maxTime, wsf);
            for (Edge e : graph[vtx])
            {
                if (!vis[e.v])
                {
                    pq.push({e.v, wsf + e.w});
                }
            }
        }
    }
    if (cnt == 0)
        return maxTime;
    return -1;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<Edge>> graph(n + 1, vector<Edge>());
    for (auto &vec : times)
    {
        addEdge(graph, vec[0], vec[1], vec[2]);
    }
    return DijkstraOptimized(graph, k, n);
}

int main()
{
    return 0;
}