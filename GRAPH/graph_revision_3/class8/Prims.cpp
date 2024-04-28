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
        return b[2] < a[2]; // rev. of def. behaviour
        return a[3] < b[3]; // def behaviour
    }
};

void Prims(vector<vector<Edge>> &graph, int src, vector<bool> &vis)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    //       src,par,wt,wsf
    pq.push({src, -1, 0, 0});
    int loopchla = 0;
    while (!pq.empty())
    {
        loopchla++;
        vector<int>
            vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int par = vec[1];
        int wt = vec[2];
        if (vis[vtx])
        {
            cout << vtx << " is already visited  " << endl;
            cout << endl;
            continue;
        }
        vis[vtx] = true;
        cout << "travelled " << vtx << " via" << par << " with weight=" << wt << endl;
        for (Edge e : graph[vtx])
        {
            if (!vis[e.v])
            {
                pq.push({e.v,
                         vtx,
                         e.w});
            }
        }
    }
    cout << endl;
    cout << "loopchla " << loopchla << endl;
}

// we can not remove vector<bool> &vis in prims algo
void PrimsOptimized(vector<vector<Edge>> &graph, int src, vector<bool> &vis)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    //       src,par,wt,wsf
    int mstWt = 0;
    vector<int> dis(vis.size(), 1e8);
    pq.push({src, -1, 0});
    int loopchla = 0;
    while (!pq.empty())
    {
        loopchla++;
        vector<int>
            vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int par = vec[1];
        int wt = vec[2];
        if (vis[vtx])
        {
            cout << vtx << " is already visited  " << endl;
            cout << endl;
            continue;
        }
        dis[vtx] = wt;
        mstWt += wt;
        vis[vtx] = true;
        cout << "travelled " << vtx << " via" << par << " with weight=" << wt << endl;
        for (Edge e : graph[vtx])
        {
            if (!vis[e.v] and e.w < dis[e.v])
            {
                dis[e.v] = e.w;
                pq.push({e.v,
                         vtx,
                         e.w});
            }
        }
    }
    cout << endl;
    cout << "loopchla " << loopchla << endl;
    cout << mstWt;
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
    PrimsOptimized(graph, 0, vis);
    return 0;
}