#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int v, bus;
    Edge(int v, int bus)
    {
        this->v = v;
        this->bus = bus;
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
void addEdge(vector<vector<Edge>> &graph, int u, int v, int bus)
{
    graph[u].push_back(Edge(v, bus));
}
// shi hai
int DijkstraWithoutVisited(vector<vector<Edge>> &graph, int src, int dest)
{
    if (src == dest)
    {
        return 0;
    }
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<bool> vis(1e6, false);
    vector<int> dis(1e6, 1e8);
    pq.push({src, -1, 0});
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int busNo = vec[1];
        int cnt = vec[2];
        if (dis[vtx] < cnt)
        {
            // cout << vtx << " is already vis with distance " << dis[vtx] << "now come with greater dis. " << wsf << endl;
            // cout << endl;
            continue;
        }
        dis[vtx] = cnt;
        // cout << "travelled " << vtx << " with shortest distance " << wsf << " or " << dis[vtx] << endl;
        for (Edge e : graph[vtx])
        {
            int newCnt = (e.bus == busNo ? cnt : cnt + 1);
            if (newCnt <= dis[e.v])
            {
                dis[e.v] = newCnt;
                pq.push({e.v, e.bus, newCnt});
            }
        }
    }
    return -1;
}
// visited array se wrong ans kyuki original dijkstra me visited islie kam krta tha kyuki ek edge se doosri edge jawge to wsf gauranteed bdhega , aur yha pe kbhi cnt ka cnt hi rh jata hai:
// to kya pta koi doosra rasta se usi vtx pr km cnt ke sath aa jaye bd me, to hme pq me equal cnt ko push krna pdega but vis array equal cnt ko push nhi hone deta

// glt hai
int Dijkstra(vector<vector<Edge>> &graph, int src, int dest)
{
    if (src == dest)
    {
        return 0;
    }
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<bool> vis(1e6, false);

    pq.push({src, -1, 0});
    while (!pq.empty())
    {
        vector<int>
            vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int busNo = vec[1];
        int cnt = vec[2];
        if (vis[vtx])
        {
            // cout << vtx << " is already vis with less distance than " << wsf << endl;
            // cout << endl;
            continue;
        }
        vis[vtx] = true;
        if (dest == vtx)
        {
            return cnt;
        }
        // cout << "travelled " << vtx << " with shortest distance " << wsf << endl;
        for (Edge e : graph[vtx])
        {
            if (!vis[e.v])
            {
                if (e.bus == busNo)
                {
                    pq.push({e.v, e.bus, cnt});
                }
                else
                {
                    pq.push({e.v, e.bus, cnt + 1});
                }
            }
        }
    }
    return -1;
}

// shi hai vis ka use hi nhi kia
int DijkstraLike(vector<vector<Edge>> &graph, int src, int dest)
{
    if (src == dest)
    {
        return 0;
    }
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    vector<int> dis(1e6, 1e7);

    pq.push({src, -1, 0});
    // vis[src] = true;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int vtx = vec[0];
        int busNo = vec[1];
        int cnt = vec[2];

        if (cnt > dis[vtx])
        {
            // cout<<vtx<<" is alredy visited"<<endl;
            continue;
        }
        // cout<<"vtx="<<vtx<<" "<<"cnt="<<cnt<<endl;
        dis[vtx] = cnt;
        if (dest == vtx)
        {
            return cnt;
        }
        for (Edge e : graph[vtx])
        {
            int x = (e.bus == busNo ? cnt : cnt + 1);
            if (x <= dis[e.v])
            {
                if (e.bus == busNo)
                {
                    // cout<<vtx<<" pushed "<<e.v<<"with cnt="<<cnt<<endl;
                    pq.push({e.v, e.bus, cnt});
                }
                else
                {
                    // cout<<vtx<<" pushed "<<e.v<<"with cnt="<<cnt+1<<endl;
                    pq.push({e.v, e.bus, cnt + 1});
                }
            }
        }
    }
    return -1;
}

int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    vector<vector<Edge>> graph(1e6, vector<Edge>());
    int c = 0;
    for (auto &vec : routes)
    {
        for (int i = 0; i < vec.size() - 1; i++)
        {
            addEdge(graph, vec[i], vec[i + 1], c);
        }
        addEdge(graph, vec[vec.size() - 1], vec[0], c);

        c++;
    }

    return DijkstraWithoutVisited(graph, source, target);
}

void addEdgeBfs(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int cycleDetectorBfs(vector<vector<int>> graph, int src, int dest)
{
    vector<bool> vis(1e6, false);
    queue<int> q;
    q.push(src);
    vis[src] = true;

    for (int e : graph[src])
    {
        if (!vis[e])
        {
            vis[e] = true;
            q.push(e);
        }
    }
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            if (vis[vtx])
            {
                continue;
            }
            if (vtx == dest)
            {
                return level + 1;
            }
            vis[vtx] = true;
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    q.push(e);
                }
            }
        }
        level++;
    }
    return -1;
}
int bfs(vector<vector<int>> graph, int src, int dest)
{
    vector<bool> vis(1e6, false);
    queue<int> q;
    q.push(src);
    vis[src] = true;

    for (int e : graph[src])
    {
        if (!vis[e])
        {
            vis[e] = true;
            q.push(e);
        }
    }
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            if (vtx == dest)
            {
                return level + 1;
            }
            for (int e : graph[vtx])
            {
                if (!vis[e])
                {
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
        level++;
    }
    return -1;
}

int specificBfs(vector<vector<int>> graph, int src, int dest, vector<vector<int>> &routes)
{
    if (src == dest)
    {
        return 0;
    }
    vector<bool> vis(routes.size(), false);
    vis[src] = true;
    queue<int> q;
    vector<bool> visStops(1e6, false);
    for (int bus : graph[src])
    {
        if (!vis[bus])
        {
            vis[bus] = true;
            for (int stop : routes[bus])
            {
                if (!visStops[stop])
                {
                    visStops[stop] = true;
                    q.push(stop);
                }
            }
        }
    }
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int vtx = q.front();
            q.pop();
            if (vtx == dest)
            {
                return level + 1;
            }
            for (int bus : graph[vtx])
            {
                if (!vis[bus])
                {
                    vis[bus] = true;
                    for (int stop : routes[bus])
                    {
                        if (!visStops[stop])
                        {
                            visStops[stop] = true;
                            q.push(stop);
                        }
                    }
                }
            }
        }
        level++;
    }
    return -1;
}
int numBusesToDestinationBfs(vector<vector<int>> &routes, int source, int target)
{
    vector<vector<int>> graph(1e6, vector<int>());
    for (int i = 0; i < routes.size(); i++)
    {
        vector<int> &vec = routes[i];
        for (int e : vec)
        {
            graph[e].push_back(i);
        }
    }
    return specificBfs(graph, source, target, routes);
}

int main()
{
    return 0;
}