#include<bits/stdc++.h>
using namespace std;





int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pq.push({grid[0][0], 0, 0});
    vis[0][0] = true;
    int ans = 0;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int val = vec[0];
        int i = vec[1];
        int j = vec[2];

        if(i==n-1 and j==m-1)
        {
            return val;
        }

        for (auto &d : dir)
        {
            int r = i + d[0];
            int c = j + d[1];

            if (r >= 0 and c >= 0 and r < n and c < m and !vis[r][c])
            {
                
                pq.push({grid[r][c], r, c});
                vis[r][c] = true;
            }
        }
    }


}

int main()
{
    return 0;
}