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
        // return a[1] < b[1]; // this-other dec order
        return b[2] < a[2];
    }
};

void prims(vector<vector<Edge>> &graph, int src)
{
    vector<bool> vis(graph.size(), false);
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    // src , wsf, wt
    pq.push({src, 0, 0});
    int mstWt = 0;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int wsf = vec[1];
        int wt = vec[2];
        if (vis[vtx])
        {
            cout << "Already visited " + to_string(vtx) + " with less wt. now comming with" + to_string(wsf) << endl;
            continue;
        }
        mstWt += wt;
        vis[vtx] = true;
        cout << vtx << " --> " << wsf << endl;
        for (Edge e : graph[vtx])
        {
            if (!vis[e.v])
            {
                pq.push({e.v, wsf + e.w, e.w});
            }
        }
    }
    cout << "Prims mstWt>>" << mstWt;
}

// void primsOptimized(vector<vector<Edge>> &graph, int src)
// {
//     priority_queue<vector<int>, vector<vector<int>>, comp> pq;
//     vector<int> dist(graph.size(), 1e7);
//     int mstWt = 0;
//     pq.push({src, 0, 0});
//     dist[src] = 0;
//     while (!pq.empty())
//     {
//         vector<int> vec = pq.top();
//         pq.pop();

//         int vtx = vec[0];
//         int wsf = vec[1];
//         int wt = vec[2];
//         if (dist[vtx] < wsf)
//         {
//             cout << "already vis " << vtx << " with " + to_string(dist[vtx]) + "  now came with" + to_string(wsf) << endl;
//             continue;
//         }
//         // dist[vtx] = wsf;
//         mstWt += wt;
//         for (Edge e : graph[vtx])
//         {
//             if (wsf + e.w < dist[e.v])
//             {
//                 dist[e.v] = wsf + e.w;
//                 pq.push({e.v, wsf + e.w, e.w});
//             }
//         }
//     }
//     cout << "PrimsOptimized mstWt>>" << mstWt;
// }

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

    //==============================================

    // addEdge(graph, 0, 1, 10);
    // addEdge(graph, 0, 3, 10);
    // addEdge(graph, 1, 2, 10);
    // addEdge(graph, 3, 2, 30);

    // addEdge(graph, 2, 8, 3);
    // addEdge(graph, 2, 7, 2);
    // addEdge(graph, 8, 7, 7);

    // addEdge(graph, 3, 4, 5);

    // addEdge(graph, 4, 5, 4);
    // addEdge(graph, 4, 6, 8);
    // addEdge(graph, 5, 6, 2);

    prims(graph, 0);
    // wrong
    //  primsOptimized(graph, 0);
    return 0;
}