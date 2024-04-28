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
    graph[v].push_back(Edge(u, w));
}

class Comp
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return b[2] < a[2];
    }
};

void dijkstra(vector<vector<Edge>> &graph, int src)
{
    vector<bool> vis(graph.size(), false);
    priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
    // {src,wt,wsf}
    pq.push({src, 0, 0});
    while (!pq.empty())
    {
        int size = pq.size();
        while (size--)
        {
            vector<int> vec = pq.top();
            pq.pop();
            int vtx = vec[0];
            int w = vec[1];
            int wsf = vec[2];
            if (vis[vtx])
                continue;
            cout << "visited vertex" << vtx << " @ wsf = " << wsf << endl;
            vis[vtx] = true;
            for (Edge e : graph[vtx])
            {
                if (!vis[e.v])
                {
                    pq.push({e.v, e.w, wsf + e.w});
                }
            }
        }
    }
}

int main()
{
    int V = 9;
    vector<vector<Edge>> graph(V, vector<Edge>());
    vector<bool> vis(V, false);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);

    addEdge(graph, 1, 7, 11);

    addEdge(graph, 1, 2, 8);
    addEdge(graph, 7, 6, 1);
    addEdge(graph, 7, 8, 7);

    addEdge(graph, 2, 8, 2);

    addEdge(graph, 8, 6, 6);

    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 5, 4);

    addEdge(graph, 6, 5, 2);
    addEdge(graph, 3, 5, 14);

    addEdge(graph, 3, 4, 9);

    addEdge(graph, 5, 4, 10);
    dijkstra(graph, 0);
    cout << endl;
    // dijkstraOptimized(graph, 0);
    return 0;
}