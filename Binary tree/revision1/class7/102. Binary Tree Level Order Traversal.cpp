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

vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
        
    }
    while (!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            TreeNode *rn = q.front();
            q.pop();
            if(level==ans.size())
            {
                ans.push_back({});
            }
            ans[level].push_back(rn->val);
            if(rn->left!=nullptr)
            {
                q.push(rn->left);
            }
            if (rn->right != nullptr)
            {
                q.push(rn->right);
            }
        }
        level++;
    }
    return ans;
}

int main()
{
    return 0;
}