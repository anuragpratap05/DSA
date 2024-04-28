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
void exactlyOneChild_help(TreeNode *root, vector<int> &ans)
{
    if (root->left == nullptr and root->right == nullptr)
    {
        return;
    }
    if (root->left == nullptr or root->right == nullptr)
    {
        ans.push_back(root->val);
    }
    if (root->left != nullptr)
    {
        exactlyOneChild_help(root->left, ans);
    }

    if (root->right != nullptr)
    {
        exactlyOneChild_help(root->right, ans);
    }
}

vector<int> exactlyOneChild(TreeNode *root)
{
    vector<int> ans;
    exactlyOneChild_help(root,ans);
    return ans;
}

int main()
{
    return 0;
}