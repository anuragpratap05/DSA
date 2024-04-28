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
class comp
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return b[2] < a[2]; // rev of def behaviour
    }
};
void dijkstra(vector<vector<Edge>> &graph, int src)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    //{src,wt,wsf}
    vector<bool> vis(graph.size(), false);
    pq.push({src, 0, 0});
    int loopchla = 0;
    while (!pq.empty())
    {
        loopchla++;
        vector<int> vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int wt = vec[1];
        int wsf = vec[2];
        if (vis[vtx])
        {
            cout << "already vis " << vtx << " with lesser weight" << endl;
            continue;
        }
        vis[vtx] = true;
        cout << vtx << "-->" << wsf << endl;
        for (Edge e : graph[vtx])
        {
            if (!vis[e.v])
            {
                pq.push({e.v, e.w, wsf + e.w});
            }
        }
    }
    cout << "loopchla=" << loopchla;
}
void dijkstraOptimized(vector<vector<Edge>> &graph, int src)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    //{src,wt,wsf}
    vector<bool> vis(graph.size(), false);
    vector<int> dist(graph.size(), 1e7);
    pq.push({src, 0, 0});
    dist[src] = 0;
    int loopchla = 0;

    while (!pq.empty())
    {
        loopchla++;

        vector<int> vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int wt = vec[1];
        int wsf = vec[2];
        if (dist[vtx] < wsf)
        {
            cout << "already vis " << vtx << " with " + to_string(dist[vtx]) + "  now came with" + to_string(wsf) << endl;
            continue;
        }
        // dist[vtx] = wsf;
        cout << vtx << "-->" << wsf << endl;
        for (Edge e : graph[vtx])
        {
            if (e.w + wsf < dist[e.v])
            {
                dist[e.v] = e.w + wsf;
                pq.push({e.v, e.w, wsf + e.w});
            }
        }
    }
    cout << "loopchla=" << loopchla;
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