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

// simple approach using space of root tonode path vector

bool find(TreeNode *root, int data, vector<TreeNode *> &ans)
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

    if (find(root->left, data, ans))
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
vector<TreeNode *> nodeToRootPath(TreeNode *node, int data)
{
    vector<TreeNode *> ans;
    find(node, data, ans);
    return ans;
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

    vector<TreeNode *> vec = nodeToRootPath(root, target->val);
    vector<int> ans;
    for (int i = 0; i < vec.size(); i++)
    {
        print_k_down(vec[i], k - i, ans, (i == 0 ? nullptr : vec[i - 1]));
    }
    return ans;
}

int distanceK_btr_help(TreeNode *root, TreeNode *target, int k, vector<int> &ans)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (root == target)
    {
        print_k_down(root, 0, ans, nullptr);
        return 1;
    }

    int lc = distanceK_btr_help(root->left, target, k, ans);
    if (lc != 0)
    {
        print_k_down(root, k - lc, ans, root->left);
        return lc + 1;
    }

    int rc = distanceK_btr_help(root->right, target, k, ans);
    if (rc != 0)
    {
        print_k_down(root, k - rc, ans, root->right);
        return rc + 1;
    }
    return 0;
}

vector<int> distanceK_btr(TreeNode *root, TreeNode *target, int k)
{

    vector<int> ans;
    distanceK_btr_help(root, target, k, ans);
    return ans;
}

int main()
{
    return 0;
}