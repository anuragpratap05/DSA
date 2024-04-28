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
    int n = heightMap.size();
    int m = heightMap[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(i==0 or j==0 or i==n-1 or j==m-1)
            {
                vis[i][j] = true;
                pq.push({heightMap[i][j], i, j});
            }
        }
    }

    int ans = 0;
    while (!pq.empty())
    {
        vector<int> vec = pq.top();
        pq.pop();
        int val = vec[0];
        int i = vec[1];
        int j = vec[2];

        for(auto& d:dir)
        {
            int r = i + d[0];
            int c = j + d[1];

            if(r>=0 and c>=0 and r<n and c<m and !vis[r][c])
            {
                if(heightMap[r][c]<val)
                {
                    ans += val - heightMap[r][c];
                    heightMap[r][c] = val;
                }
                pq.push({heightMap[r][c], r, c});
                vis[r][c] = true;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}