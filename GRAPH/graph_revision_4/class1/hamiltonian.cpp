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


bool findVtx(vector<vector<Edge>> &graph, int osrc, int dest)
{
    for (Edge e : graph[dest])
    {
        if (e.v == osrc)
        {
            return true;
        }
    }
    return false;
}

void dfs(vector<vector<Edge>> &graph, int src, int osrc, int dest, vector<bool> &vis, int cnt, string psf)
{
    if (cnt == graph.size())
    {
        string str = psf + to_string(src);
        if (findVtx(graph, osrc, src))
        {
            str += "*";
        }
        cout << str << endl;
        return;
    }

    vis[src] = true;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            dfs(graph, e.v, osrc, dest, vis, cnt + 1, psf + to_string(src));
        }
    }
    vis[src] = false;
}
void hamiltonian(vector<vector<Edge>> &graph, int src, int dest)
{
    vector<bool> vis(graph.size(), false);
    dfs(graph, src, src, dest, vis, 1, "");
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
    hamiltonian(graph, 0, 6);
    return 0;
}