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

void exactlyOneChild(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr or (root->left == nullptr and root->right == nullptr))
    {
        return;
    }
    if (root->left == nullptr or root->right == nullptr)
    {
        ans.push_back(root->val);
    }
    exactlyOneChild(root->left,ans);
    exactlyOneChild(root->right,ans);
}

vector<int> exactlyOneChild(TreeNode *root)
{
    vector<int> ans;
    exactlyOneChild(root,ans);
    return ans;
}

int main()
{
    return 0;
}