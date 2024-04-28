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
    // graph[v].push_back(Edge(u, w));
}
class comp
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return b[1] < a[1];
    }
};
int Dijkstra(vector<vector<Edge>> &graph, int src, vector<bool> &vis, vector<int> &dis)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    pq.push({src, 0});
    // src ,wsf
    int ans = 0;
    while (!pq.empty())
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
        dis[vtx] = wsf;
        ans = max(ans, wsf);
        for (Edge e : graph[vtx])
        {
            if (!vis[e.v])
            {
                if (wsf + e.w < dis[e.v])
                {
                    dis[e.v] = wsf + e.w;
                    pq.push({e.v, wsf + e.w});
                }
            }
        }
    }
    for (int i = 1; i < dis.size(); i++)
    {
        if (dis[i] == 1e9)
        {
            return -1;
        }
    }
    return ans;
}
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<Edge>> graph(n + 1, vector<Edge>());
    for (auto &vec : times)
    {
        addEdge(graph, vec[0], vec[1], vec[2]);
    }
    vector<bool> vis(n + 1, false);
    vector<int> dis(n + 1, 1e9);
    return Dijkstra(graph, k, vis, dis);
}

int main()
{
    return 0;
}