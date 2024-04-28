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

pair<int, string> heavyPath(vector<vector<Edge>> &graph, int src, int dest, vector<bool> &vis)
{
    if (src == dest)
    {
        return {0, to_string(src)};
    }
    vis[src] = true;
    pair<int, string> myAns = {-1, ""};
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            pair<int, string> recAns = heavyPath(graph, e.v, dest, vis);
            if (recAns.first != -1 and recAns.first + e.w > myAns.first)
            {
                myAns.first = recAns.first + e.w;
                myAns.second = to_string(src) + recAns.second;
            }
        }
    }
    vis[src] = false;
    return myAns;
}

int main()
{
    int V = 7;
    vector<vector<Edge>> graph(V, vector<Edge>());
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 1, 2, 10);

    // addEdge(graph, 2, 7, 2);
    // addEdge(graph, 2, 8, 4);
    // addEdge(graph, 7, 8, 3);

    addEdge(graph, 3, 4, 2);

    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);
    vector<bool> vis(V, false);
    pair<int, string> p = heavyPath(graph, 0, 6, vis);
    cout << p.first << " " << p.second << endl;
    return 0;
}