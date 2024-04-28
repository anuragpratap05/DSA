#include<bits/stdc++.h>
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

int swimInWater(vector<vector<int>> &grid)
{
    int n=grid.size();
    int m=n;
    int mintime = 0;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pq.push({grid[0][0],0,0});
    vis[0][0]=true;
    while(!pq.empty())
    {
        vector<int>vec=pq.top();
        pq.pop();
        int val=vec[0];
        int i=vec[1];
        int j=vec[2];
        mintime=max(mintime,val);
        if(i==n-1 and j==m-1)
        {
            break;
        }
        for (vector<int> &v : dir)
        {
            int nr = i + v[0];
            int nc = j + v[1];
            if (nr < n and nr >= 0 and nc < m and nc >= 0 and !vis[nr][nc])
            {

                pq.push({grid[nr][nc], nr, nc});
                vis[nr][nc] = true;
            }
        }
    }
    return mintime;
}

int main()
{
    return 0;
}