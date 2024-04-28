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

// O(n)
int countNodes2(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int leftnodes = countNodes2(root->left);
    int rightnodes = countNodes2(root->right);
    return leftnodes + rightnodes + 1;
}

int depthOfTree(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int depth = 0;
    TreeNode *node = root;
    while (node->left != nullptr)
    {
        depth++;
        node = node->left;
    }
    return depth;
}

bool nodeExistAtIdx(TreeNode *root, int idx, int depth)
{
    if (root == nullptr)
        return false;
    TreeNode *node = root;
    int s = 0, e = pow(2, depth) - 1;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (idx <= mid)
        {
            node = node->left;
            e = mid;
        }
        else
        {
            node = node->right;
            s = mid + 1;
        }
    }
    return node != nullptr;
}

// o(d^2) , where d=depth of tree
int countNodes(TreeNode *root)
{
    int depth = depthOfTree(root);
    int s = 0, e = pow(2, depth) - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool nodeExist = nodeExistAtIdx(root, mid, depth);
        if (nodeExist)
            s = mid + 1;
        else
            e = mid - 1;
    }
    int totalNodes = (pow(2, depth) - 1) + s;
    return totalNodes;
}

int main()
{
    return 0;
}