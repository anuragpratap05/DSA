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

bool nodeToRootPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &ans)
{
    if (root == nullptr)
        return false;
    if (root == target)
    {
        ans.push_back(target);
        return true;
    }
    bool found = nodeToRootPath(root->left, target, ans) || nodeToRootPath(root->right, target, ans);
    if (found)
        ans.push_back(root);
    return found;
}

void printkDown(TreeNode *node, int k, TreeNode *blockNd, vector<int> &ans)
{
    if (node == nullptr or node == blockNd)
        return;
    if (k == 0)
    {
        ans.push_back(node->val);
        return;
    }
    printkDown(node->left, k - 1, blockNd, ans);
    printkDown(node->right, k - 1, blockNd, ans);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    if (root == nullptr)
        return {};
    vector<TreeNode *> path;
    nodeToRootPath(root, target, path);
    vector<int> ans;
    for (int i = 0; i < path.size(); i++)
    {
        TreeNode *blockNd = i == 0 ? nullptr : path[i - 1];
        printkDown(path[i], k - i, blockNd, ans);
    }
    return ans;
}

int main()
{
    return 0;
}