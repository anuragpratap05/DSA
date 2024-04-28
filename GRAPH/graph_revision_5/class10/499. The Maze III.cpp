#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> nav = {"u", "r", "d", "l"};

class trplet
{
public:
    int idx;
    int wsf;
    string str;
    trplet(int idx, int wsf, string str)
    {
        this->idx = idx;
        this->wsf = wsf;
        this->str = str;
    }
};

class comp
{
public:
    bool operator()(trplet &a, trplet &b)
    {
        if (a.wsf == b.wsf)
        {
            return b.str < a.str;
        }
        return b.wsf < a.wsf;
    }
};

string hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n = maze.size();
    int m = maze[0].size();

    int sr = start[0];
    int sc = start[1];

    int er = destination[0];
    int ec = destination[1];

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    priority_queue<trplet, vector<trplet>, comp> pq;
    int sIdx = (sr * m) + sc;
    // src, wsf
    pq.push(trplet(sIdx, 0, ""));

    while (!pq.empty())
    {
        trplet t = pq.top();
        pq.pop();
        int idx = t.idx;
        int i = idx / m;
        int j = idx % m;
        int wsf = t.wsf;
        string strSoFar = t.str;

        if (i == er and j == ec)
        {
            return strSoFar;
        }
        if (vis[i][j])
        {
            continue;
        }
        vis[i][j] = true;
        for (int itr = 0; itr < dirs.size(); itr++)
        {
            vector<int> &dir = dirs[itr];
            int r = i;
            int c = j;
            int steps = 0;
            string curStr = strSoFar + nav[itr];
            bool iBroke = false;
            while (r >= 0 and c >= 0 and r < n and c < m and maze[r][c] == 0)
            {
                r += dir[0];
                c += dir[1];
                steps++;
                if (r == er and c == ec)
                {
                    iBroke = true;
                    pq.push(trplet((r * m) + c, wsf + steps, curStr));
                }
            }
            if (iBroke)
            {
                continue;
            }
            r -= dir[0];
            c -= dir[1];
            steps--;
            if (!vis[r][c])
            {
                pq.push(trplet((r * m) + c, wsf + steps, curStr));
            }
        }
    }
    return "impossible";
}
string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole)
{
    return hasPath(maze, ball, hole);
}

int main()
{
    return 0;
}