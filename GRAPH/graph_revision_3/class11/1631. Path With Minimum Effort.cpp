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
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int minimumEffortPath(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dis(n, vector<int>(m, 1e7));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0});
    int ans = 0;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int wt = vec[0];
        int i = vec[1];
        int j = vec[2];
        ans = max(ans, wt);
        if (i == n - 1 and j == m - 1)
        {
            return ans;
        }

        if (vis[i][j] or dis[i][j] >= wt)
        {
            continue;
        }
        dis[i][j] = wt;
        vis[i][j] = true;
        for (vector<int> &v : dir)
        {
            int r = i + v[0];
            int c = j + v[1];
            if (r >= 0 and c >= 0 and r < n and c < m and !vis[r][c])
            {
                int ht = abs(heights[i][j] - heights[r][c]);
                if (ht < dis[r][c])
                {
                    dis[r][c] = ht;
                    pq.push({ht, r, c});
                }
            }
        }
    }
    return 0;
}

int main()
{
    return 0;
}