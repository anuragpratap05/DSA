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
class comp
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return b[2] < a[2]; // rev. of def. behaviour
        return a[3] < b[3]; // def behaviour
    }
};
void addEdge(vector<vector<Edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

int PrimsOptimized(vector<vector<Edge>> &graph, int src, vector<bool> &vis)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    //       src,par,wt,wsf
    int mstWt = 0;
    vector<int> dis(vis.size(), 1e8);
    pq.push({src, -1, 0});
    while (!pq.empty())
    {
        vector<int>
            vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int par = vec[1];
        int wt = vec[2];
        if (vis[vtx])
        {
            // cout << vtx << " is already visited  " << endl;
            // cout << endl;
            continue;
        }
        dis[vtx] = wt;
        mstWt += wt;
        vis[vtx] = true;
        // cout << "travelled " << vtx << " via" << par << " with weight=" << wt << endl;
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
    // cout << endl;
    // cout << "loopchla " << loopchla << endl;
    // cout << mstWt;
    return mstWt;
}
int findwt(vector<vector<int>> &points, int i, int j)
{
    int a = abs(points[i][0] - points[j][0]);
    int b = abs(points[i][1] - points[j][1]);
    return a + b;
}
int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<Edge>> graph(n, vector<Edge>());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            addEdge(graph, i, j, findwt(points, i, j));
            // edges.push_back({findwt(points, i, j), i, j});
        }
    }
    vector<bool> vis(n, false);
    return PrimsOptimized(graph, 0, vis);
}

int main()
{
    return 0;
}
