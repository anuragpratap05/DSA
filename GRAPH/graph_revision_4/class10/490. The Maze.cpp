#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool bfs(vector<vector<int>> &maze, int x, int y, int dstx, int dsty)
    {
        queue<int> q;
        int n = maze.size();
        int m = maze[0].size();
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push(x * m + y);
        maze[x][y] = -1;
        while (!q.empty())
        {

            int idx = q.front();
            q.pop();
            int i = idx / m;
            int j = idx % m;
            for (vector<int> &vec : dirs)
            {

                int r = i, c = j;
                while (r >= 0 and c >= 0 and r < n and c < m and maze[r][c] != 1)
                {
                    r = r + vec[0];
                    c = c + vec[1];
                }
                r -= vec[0];
                c -= vec[1];
                if (maze[r][c] == -1)
                {
                    continue;
                }
                if (r == dstx and c == dsty)
                {
                    return true;
                }

                maze[r][c] = -1;
                q.push(r * m + c);
            }
        }
        return false;
    }

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        return bfs(maze, start[0], start[1], destination[0], destination[1]);
    }
};

int main()
{
    return 0;
}