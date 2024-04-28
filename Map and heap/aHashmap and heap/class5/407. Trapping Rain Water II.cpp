#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

int trapRainWater(vector<vector<int>> &heightMap)
{

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int n = heightMap.size();
    int m = heightMap[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                pq.push({heightMap[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }
    int ans = 0;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (!pq.empty())
    {
        vector<int> p = pq.top();
        pq.pop();
        int val = p[0];
        int r = p[1];
        int c = p[2];
        for (vector<int> &vec : dir)
        {
            int nr = r + vec[0];
            int nc = c + vec[1];
            if (nr < n and nr >= 0 and nc < m and nc >= 0 and !vis[nr][nc])
            {
                if (val > heightMap[nr][nc])
                {
                    ans += val - heightMap[nr][nc];
                }
                pq.push({heightMap[nr][nc], nr, nc});
                vis[nr][nc]=true;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}