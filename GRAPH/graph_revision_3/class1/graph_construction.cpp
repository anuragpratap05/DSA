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

void display(vector<vector<Edge>> &graph)
{
    for (int u = 0; u < graph.size(); u++)
    {
        cout << u << "-->";
        for (auto edge : graph[u])
        {
            cout << "(" << edge.v << "," << edge.w << ") ,";
        }
        cout << endl;
    }
}

pair<int, string> heavyPath(vector<vector<Edge>> &graph, int src, int dest, vector<bool> &vis)
{
    if (src == dest)
    {
        return {0, to_string(dest)};
    }
    vis[src] = true;
    pair<int, string> myPair = {-1, ""};
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            pair<int, string> recAns = heavyPath(graph, e.v, dest, vis);
            if (recAns.first != -1 and recAns.first + e.w > myPair.first)
            {
                myPair.first = recAns.first + e.w;
                myPair.second = to_string(src) + recAns.second;
            }
        }
    }
    vis[src] = false;
    return myPair;
}

void hamiltonian(vector<vector<Edge>> &graph, int src, vector<string> &ans, int osrc, vector<bool> &vis, int cnt, string psf)
{
    vis[src] = true;

    if (graph.size() == cnt + 1)
    {
        psf = psf + to_string(src);
        bool conn = false;
        for (Edge e : graph[src])
        {
            if (e.v == osrc)
            {
                conn = true;
                break;
            }
        }
        if (conn)
        {
            psf += "*";
        }
        ans.push_back(psf);
    }

    for (Edge e : graph[src])
    {
        if (!vis[e.v])
        {
            hamiltonian(graph, e.v, ans, osrc, vis, cnt + 1, psf + to_string(src));
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
    addEdge(graph, 0, 6, 44);
    vector<bool> vis(V, false);
    // display(graph);
    // pair<int, string> p = heavyPath(graph, 0, 6, vis);
    // cout << p.first << "   " << p.second;
    vector<string> ans;

    hamiltonian(graph, 0, ans, 0, vis, 0, "");
    for (auto s : ans)
    {
        cout << s << endl;
    }
    return 0;
}