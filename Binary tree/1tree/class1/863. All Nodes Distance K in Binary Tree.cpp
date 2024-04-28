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
// with space
vector<TreeNode *> nodeToRootPath(TreeNode *root, TreeNode *tar)
{
    // vector<TreeNode *> ans;

    if (root == nullptr)
    {
        return {};
    }
    if (root == tar)
    {
        vector<TreeNode *> ans;
        ans.push_back(root);
        return ans;
    }

    vector<TreeNode *> left = nodeToRootPath(root->left, tar);
    vector<TreeNode *> right = nodeToRootPath(root->right, tar);

    if (left.size() == 0 and right.size() == 0)
    {
        return {};
    }
    else
    {
        if (left.size() != 0)
        {
            left.push_back(root);
            return left;
        }
        else
        {
            right.push_back(root);
            return right;
        }
        // ans.push_back(root);
        // return ans;
    }
}

void print_k_down(TreeNode *root, int k, vector<int> &ans, TreeNode *block)
{
    if (root == nullptr or root == block)
    {
        return;
    }
    if (k == 0)
    {
        ans.push_back(root->val);
        return;
    }
    print_k_down(root->left, k - 1, ans, block);
    print_k_down(root->right, k - 1, ans, block);
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    vector<TreeNode *> paths = nodeToRootPath(root, target);
    vector<int> ans;
    for (int i = 0; i < paths.size(); i++)
    {
        print_k_down(paths[i], k - i, ans, (i > 0 ? paths[i - 1] : nullptr));
    }
    return ans;
}

int find(TreeNode *root, TreeNode *target, vector<int> &ans, int k)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root == target)
    {
        print_k_down(root, k, ans, nullptr);
        return 1;
    }

    int l = find(root->left, target, ans, k);
    if(l!=0)
    {
        print_k_down(root,k-l,ans,root->left);
        return l+1;
    }

    int r = find(root->right, target, ans, k);
    if (r != 0)
    {
        print_k_down(root, k - r, ans, root->right);
        return r + 1;
    }
    return 0;
}

// without space
vector<int> distanceK_2(TreeNode *root, TreeNode *target, int k)
{
    vector<int>ans;
    find(root,target,ans,k);
    return ans;
}

int main()
{
    return 0;
}