#include <bits/stdc++.h>
using namespace std;

class edge
{
public:
    int v, w;
    edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addedge(vector<vector<edge>> &graph, int u, int v, int w)
{
    graph[u].push_back(edge(v, w));
    graph[v].push_back(edge(u, w));
}

void display(vector<vector<edge>> &graph)
{
    int n = graph.size();

    for (int i = 0; i < n; i++)
    {
        cout << i << "  ";
        for (auto edg : graph[i])
        {
            cout << "(" << edg.v << "," << edg.w << ")";
        }
        cout << endl;
    }
}

int find_edge(vector<vector<edge>> &graph, int u, int v)
{
    for (int i = 0; i < graph[u].size(); i++)
    {
        edge e = graph[u][i];
        if (e.v == v)
        {
            return i;
        }
    }
    return -1;
}

void remove_edge(vector<vector<edge>> &graph, int u, int v)
{
    int idx = find_edge(graph, u, v);
    // int idx1 = find_edge(graph, v, u);
    swap(graph[u][idx], graph[u][graph[u].size() - 1]);
    graph[u].pop_back();

    // swap(graph[v][idx1], graph[v][graph[v].size() - 1]);
    // graph[v].pop_back();
}

void remove_vtx(vector<vector<edge>> &graph, int u)
{

    while (graph[u].size() > 0)
    {
        edge e = graph[u][graph[u].size() - 1];
        int v = e.v;
        cout << v << endl;
        remove_edge(graph, v, u);
        graph[u].pop_back();
    }
}

bool has_path(vector<vector<edge>> &graph, int src, int dest, vector<bool> &vis)
{
    if (src == dest)
    {
        return true;
    }
    vis[src] = true;

    for (auto e : graph[src])
    {
        if (!vis[e.v])
        {

            bool ans = has_path(graph, e.v, dest, vis);
            if (ans)
            {
                return true;
            }
        }
    }
    vis[src] = false;
    return false;
}

// 1971
bool validPath_help(int n, vector<vector<int>> &edges, int source, int destination, vector<bool> &vis)
{

    if (source == destination)
    {
        return true;
    }
    vis[source] = true;

    for (auto e : edges[source])
    {
        if (!vis[e])
        {

            bool ans = validPath_help(n, edges, e, destination, vis);
            if (ans)
            {
                return true;
            }
        }
    }
    // vis[source] = false;
    //  jab ek bar nhi ja paye us raste se to dubara usi raste se kaise ja paynge
    return false;
}

void addedge2(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<bool> vis(n, false);

    vector<vector<int>> graph(n, vector<int>());
    for (auto &vec : edges)
    {
        addedge2(graph, vec[0], vec[1]);
    }
    return validPath_help(n, graph, source, destination, vis);
}

int main()
{

    int V = 9;
    vector<vector<edge>> graph(V, vector<edge>());

    addedge(graph, 0, 3, 10);
    addedge(graph, 0, 1, 10);
    addedge(graph, 2, 3, 40);
    addedge(graph, 1, 2, 10);

    addedge(graph, 2, 7, 2);
    addedge(graph, 2, 8, 4);
    addedge(graph, 7, 8, 3);

    addedge(graph, 3, 4, 2);

    addedge(graph, 4, 5, 2);
    addedge(graph, 4, 6, 8);
    addedge(graph, 5, 6, 3);

    display(graph);

    cout << endl;
    cout << endl;

    // remove_edge(graph, 3, 2);
    remove_vtx(graph, 3);

    display(graph);

    return 0;
}