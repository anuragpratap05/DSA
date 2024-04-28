#include<bits/stdc++.h>
using namespace std;

// 687  1339 home work hai!
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

int dfs(vector<vector<int>> &tree,int root, vector<bool> &hasApple,vector<bool>& vis)
{
    vis[root]=true;
    int time=0;
    for(int e:tree[root])
    {
        if(!vis[e])
        {
            time+=dfs(tree,e,hasApple,vis);
        }
    }
    if(time!=0)
    {
        return time+2;
    }
    else if(hasApple[root])
    {
        return 2;
    }
    return 0;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    vector<vector<int>> tree(n,vector<int>());
    for(vector<int>& vec:edges)
    {
        int u=vec[0];
        int v=vec[1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }   

    vector<bool> vis(n,false);

    int ans=dfs(tree,0,hasApple,vis);
    if(ans==0)
    {
        return ans;
    }
    return ans-2;

}

int main()
{
    return 0;
}