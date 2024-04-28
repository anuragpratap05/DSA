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
vector<int> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    while (!q.empty())
    {
        int size = q.size();
        ans.push_back(q.front()->val);
        while (size--)
        {
            TreeNode *rn = q.front();
            q.pop();
            
            
            if (rn->right != nullptr)
            {
                q.push(rn->right);
            }
            if (rn->left != nullptr)
            {
                q.push(rn->left);
            }
            
        }
        level++;
    }
    return ans;
}
vector<int> rightSideView(TreeNode *root)
{
    return levelOrder(root);
}

int main()
{
    return 0;
}