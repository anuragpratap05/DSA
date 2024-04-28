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
void printKLevelDown(TreeNode *root, int k, TreeNode *blockNode, vector<int> &ans)
{
    if (root == nullptr or root == blockNode)
        return;
    if (k == 0)
    {
        // cout << root->val;
        ans.push_back(root->val);
        return;
    }
    printKLevelDown(root->left, k - 1, blockNode, ans);
    printKLevelDown(root->right, k - 1, blockNode, ans);
}

bool nodeToRootPath(TreeNode *root, TreeNode *tar, vector<TreeNode *> &ans)
{
    if (root == nullptr)
        return false;
    if (root == tar)
    {
        ans.push_back(root);
        return true;
    }
    bool found = nodeToRootPath(root->left, tar, ans) || nodeToRootPath(root->right, tar, ans);
    // if (lfound)
    // {
    //     ans.push_back(root);
    //     return true;
    // }
    // bool rfound = nodeToRootPath(root->right, tar, ans);
    // if (rfound)
    // {
    //     ans.push_back(root);
    //     return true;
    // }
    if (found)
        ans.push_back(root);
    return found;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    vector<TreeNode *> nodeToroot;
    nodeToRootPath(root, target, nodeToroot);
    vector<int> ans;
    for (int i = 0; i < nodeToroot.size(); i++)
    {
        TreeNode *blockNode = i == 0 ? nullptr : nodeToroot[i - 1];
        printKLevelDown(nodeToroot[i], k - i, blockNode, ans);
    }
    return ans;
}

int main()
{
    return 0;
}