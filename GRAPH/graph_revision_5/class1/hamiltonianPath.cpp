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

void hamiltonian(vector<vector<Edge>> &graph, int src, int cnt, string psf, int oSrc, vector<bool> &vis)
{
    if (cnt == graph.size() - 1)
    {
        psf += to_string(src);
        for (Edge e : graph[src])
        {
            if (e.v == oSrc)
            {
                psf += "*";
            }
        }

        cout << psf << endl;
        return;
    }
    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            hamiltonian(graph, e.v, cnt + 1, psf + to_string(src), oSrc, vis);
        }
    }
    vis[src] = false;
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

    addEdge(graph, 0, 6, 3);

    vector<bool> vis(V, false);

    hamiltonian(graph, 0, 0, "", 0, vis);

    return 0;
}