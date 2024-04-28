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

int kthSmallest(vector<vector<int>> &matrix, int k)
{

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int c = 0;
    int n = matrix.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    pq.push({matrix[0][0], 0, 0});
    int val;
    while (c < k)
    {
        auto &vec = pq.top();
        pq.pop();
        val = vec[0];
        int i = vec[1];
        int j = vec[2];
        c++;
        int r1=i;
        int c1=j+1;
        int r2=i+1;
        int c2=j;

        if(r1<n and c1<n and !vis[r1][c1])
        {
            pq.push({matrix[r1][c1],r1,c1});
            vis[r1][c1]=true;
        }

        if (r2 < n and c2 < n and !vis[r2][c2])
        {
            pq.push({matrix[r2][c2], r2, c2});
            vis[r2][c2] = true;
        }
    }
    return val;
}

int main()
{
    return 0;
}