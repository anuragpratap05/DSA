#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dis(n, vector<int>(m, 1e7));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, start[0], start[1]});
    // dis[start[0]][start[1]] = 0;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int wt = vec[0];
        int i = vec[1];
        int j = vec[2];
        if (dis[i][j] < wt)
        {
            continue;
        }
        if (i == destination[0] and j == destination[1])
        {
            return wt;
        }
        dis[i][j] = wt;
        cout << i << "," << j << " pushed:" << endl;
        for (auto &vec1 : dir)
        {
            int r = i + vec1[0];
            int c = j + vec1[1];
            int cnt = 0;
            while (r >= 0 and c >= 0 and r < n and c < m and maze[r][c] != 1)
            {
                r = r + vec1[0];
                c = c + vec1[1];
                cnt++;
            }
            r = r - vec1[0];
            c = c - vec1[1];
            
            if (wt + cnt < dis[r][c])
            {
                cout << r << "," << c << endl;

                dis[r][c] = wt + cnt;
                pq.push({wt + cnt, r, c});
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}