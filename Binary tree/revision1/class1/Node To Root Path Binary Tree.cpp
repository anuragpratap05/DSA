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

bool find(TreeNode *root, int data, vector<TreeNode*> &ans)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->val == data)
    {
        ans.push_back(root);
        return true;
    }

    if (find(root->left, data,ans))
    {
        ans.push_back(root);
        return true;
    }
    if (find(root->right, data, ans))
    {
        ans.push_back(root);
        return true;
    }
    return false;
}
vector<TreeNode*> nodeToRootPath(TreeNode* node, int data)
{
    vector<TreeNode*>ans;
     find(node,data,ans);
     return ans;
}

int main()
{
    return 0;
}