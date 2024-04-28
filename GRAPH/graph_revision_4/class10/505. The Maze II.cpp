#include <bits/stdc++.h>
using namespace std;
// [ [ 0, 0, 0, 0, 0, 0 ], [ 0, 1, 1, 1, 1, 0 ], [ 0, 0, 0, 0, 0, 0 ] ]
//     [0, 1]
//     [2, 5]

// for above TC this accepted code on LC will fail pq gaurantees us min dis when a node is removed from pq not at while pushing it
vector<vector<int>>
    dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int m = maze[0].size();
    int n = maze.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e7));
    // {wt,x,y}
    pq.push({0, start[0], start[1]});
    dist[start[0]][start[1]] = 0;

    while (!pq.empty())
    {
        vector<int> vect = pq.top();
        pq.pop();
        int wt = vect[0];
        int i = vect[1];
        int j = vect[2];
        for (vector<int> &vec : dirs)
        {
            int dis = 0;
            int r = i, c = j;
            while (r >= 0 and c >= 0 and r < n and c < m and maze[r][c] == 0)
            {
                r = r + vec[0];
                c = c + vec[1];
                dis++;
            }
            r -= vec[0];
            c -= vec[1];
            dis--;
            if (dist[r][c] <= wt + dis)
            {
                continue;
            }
            if (r == destination[0] and c == destination[1])
            {
                return wt + dis;
            }
            pq.push({wt + dis, r, c});
            dist[r][c] = wt + dis;
        }
    }
    return -1;
}

int main()
{
    return 0;
}