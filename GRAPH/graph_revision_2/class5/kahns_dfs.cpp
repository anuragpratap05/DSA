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

bool kans_dfs(vector<vector<int>>& graph,vector<bool>& vis,vector<bool>& path,int src)
{
    vis[src] = true;
    path[src] = true;

    for(int e:graph[src])
    {
        if(!vis[e])
        {
            bool ans = kans_dfs(graph, vis, path, e);
            if(!ans)
            {
                return false;
            }
        }
        else
        {
            if(path[e])
            {
                return false;
            }
        }
    }

    path[src] = false;
    return true;
}

int main()
{
    return 0;
}