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
class p
{
public:
    int heavy = 0;
    string psf = "";
    p(int heavy, string psf)
    {
        this->heavy = heavy;
        this->psf = psf;
    }
};

p heavy_path(vector<vector<edge>> &graph, int src, int dest, vector<bool> &vis)
{
    if (src == dest)
    {
        p base(0, to_string(src));
        return base;
    }

    p myp(-1, "");
    vis[src] = true;

    for (edge e : graph[src])
    {
        if (!vis[e.v])
        {
            p rec_ans = heavy_path(graph, e.v, dest, vis);
            if (rec_ans.heavy != -1 and rec_ans.heavy + e.w > myp.heavy)
            {
                myp.heavy = rec_ans.heavy + e.w;
                myp.psf = to_string(src)+ rec_ans.psf;
            }
        }
    }
    vis[src] = false;
    return myp;
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

   // addedge(graph, 3, 4, 2);

    addedge(graph, 4, 5, 2);
    addedge(graph, 4, 6, 8);
    addedge(graph, 5, 6, 3);
    vector<bool> vis(V, false);

    p ans = heavy_path(graph, 0, 6, vis);
    cout << ans.heavy << " " << ans.psf;
    return 0;
}