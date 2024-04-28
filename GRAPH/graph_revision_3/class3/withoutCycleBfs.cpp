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
void withoutCycleBfs(vector<vector<Edge>> &graph, int src)
{
    vector<bool> vis(graph.size(), false);
    queue<int> q;
    vis[src] = true;
    q.push(src);
    int level = 0;
    while (!q.empty())
    {
        cout << "level:" << level << "->";
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            cout << vtx << ",";
            for (Edge e : graph[vtx])
            {
                if (!vis[e.v])
                {
                    vis[e.v] = true;
                    q.push(e.v);
                }
            }
        }
        cout << endl;
        level++;
    }
}

int main()
{
    int V = 9;
    vector<vector<Edge>> graph(V, vector<Edge>());
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 1, 2, 10);

    addEdge(graph, 2, 7, 2);
    addEdge(graph, 2, 8, 4);
    addEdge(graph, 7, 8, 3);

    addEdge(graph, 3, 4, 2);

    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 8);
    addEdge(graph, 5, 6, 3);

    withoutCycleBfs(graph, 0);

    return 0;
}