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

int level_order(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int ans;

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        // cout<<"level:"<<level<<"-->";
        while (size--)
        {
            TreeNode *rn = q.front();
            q.pop();
            ans = rn->val;
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
int findBottomLeftValue(TreeNode *root)
{
    return level_order(root);
}

int main()
{
    return 0;
}