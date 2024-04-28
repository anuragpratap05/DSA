#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class comp
{
public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return b[1] < a[1];
    }
};

bool hasPathOptimized(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n = maze.size();
    int m = maze[0].size();

    int sr = start[0];
    int sc = start[1];

    int er = destination[0];
    int ec = destination[1];

    vector<vector<int>> dist(n, vector<int>(m, 1e8));

    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    int sIdx = (sr * m) + sc;
    // src, wsf
    pq.push({sIdx, 0});
    dist[sr][sc] = 0;

    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int idx = vec[0];
        int i = idx / m;
        int j = idx % m;
        int wsf = vec[1];

        if (i == er and j == ec)
        {
            return true;
        }
        if (wsf > dist[i][j])
        {
            continue;
        }
        // vis[i][j] = true;
        for (vector<int> &dir : dirs)
        {
            int r = i;
            int c = j;
            int steps = 1;
            while (r >= 0 and c >= 0 and r < n and c < m and maze[r][c] == 0)
            {
                r += dir[0];
                c += dir[1];
                steps++;
            }
            r -= dir[0];
            c -= dir[1];
            steps--;
            if (wsf + steps < dist[r][c])
            {
                dist[r][c] = wsf + steps;
                pq.push({(r * m) + c, wsf + steps});
            }
        }
    }
    return false;
}

bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n = maze.size();
    int m = maze[0].size();

    int sr = start[0];
    int sc = start[1];

    int er = destination[0];
    int ec = destination[1];

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    int sIdx = (sr * m) + sc;
    // src, wsf
    pq.push({sIdx, 0});

    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int idx = vec[0];
        int i = idx / m;
        int j = idx % m;
        int wsf = vec[1];

        if (i == er and j == ec)
        {
            return true;
        }
        if (vis[i][j])
        {
            continue;
        }
        vis[i][j] = true;
        for (vector<int> &dir : dirs)
        {
            int r = i;
            int c = j;
            int steps = 1;
            while (r >= 0 and c >= 0 and r < n and c < m and maze[r][c] == 0)
            {
                r += dir[0];
                c += dir[1];
                steps++;
            }
            r -= dir[0];
            c -= dir[1];
            steps--;
            if (!vis[r][c])
            {
                pq.push({(r * m) + c, wsf + steps});
            }
        }
    }
    return false;
}



int main()
{
    return 0;
}