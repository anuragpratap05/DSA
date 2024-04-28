#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
vector<string> nav = {"d", "l", "r", "u"};

class pairs
{
public:
    int wt, i, j;
    string directionString;
    pairs(int wt, int i, int j, string directionString)
    {
        this->wt = wt;
        this->i = i;
        this->j = j;
        this->directionString = directionString;
    }
};
class comp
{
public:
    bool operator()(pairs &a, pairs &b)
    {
        if (a.wt == b.wt)
        {
            return b.directionString < a.directionString;
        }
        return b.wt < a.wt;
    }
};

string shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int m = maze[0].size();
    int n = maze.size();
    priority_queue<pairs, vector<pairs>, comp> pq;
    vector<vector<int>> dist(n, vector<int>(m, 1e7));
    // pairs=(wt,i,j,"")
    pq.push(pairs(0, start[0], start[1], ""));
    dist[start[0]][start[1]] = 0;
    string ans = "";
    while (!pq.empty())
    {
        pairs p = pq.top();
        pq.pop();
        int wt = p.wt;
        int i = p.i;
        int j = p.j;
        string directionString = p.directionString;
        if (dist[i][j] < wt)
        {
            continue;
        }
        if (i == destination[0] and j == destination[1])
        {
            return p.directionString;
        }
        for (int d = 0; d < dirs.size(); d++)
        {
            vector<int> &vec = dirs[d];
            int dis = 0;
            int r = i, c = j;
            bool isLoopBreakedByMe = false;
            while (r >= 0 and c >= 0 and r < n and c < m and maze[r][c] == 0)
            {
                r = r + vec[0];
                c = c + vec[1];
                dis++;
                if (r == destination[0] and c == destination[1])
                {
                    if (wt + dis <= dist[r][c])
                    {
                        pq.push(pairs(wt + dis, r, c, directionString + nav[d]));
                        dist[r][c] = wt + dis;
                        isLoopBreakedByMe = true;
                    }
                }
            }
            if (isLoopBreakedByMe)
            {
                continue;
            }
            r -= vec[0];
            c -= vec[1];
            dis--;

            if (dist[r][c] < wt + dis or (r == i and c == j))
            {
                continue;
            }

            pq.push(pairs(wt + dis, r, c, directionString + nav[d]));
            dist[r][c] = wt + dis;
        }
    }
    return "impossible";
}
string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole)
{
    return shortestDistance(maze, ball, hole);
}

int main()
{
    return 0;
}