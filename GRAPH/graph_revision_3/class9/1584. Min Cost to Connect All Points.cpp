#include<bits/stdc++.h>
using namespace std;
void PrimsOptimized(vector<vector<Edge>> &graph, int src, vector<bool> &vis)
{
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    //       src,par,wt,wsf
    int mstWt = 0;
    vector<int> dis(vis.size(), 1e8);
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
int minCostConnectPoints(vector<vector<int>> &points)
{
}

int main()
{
    return 0;
}