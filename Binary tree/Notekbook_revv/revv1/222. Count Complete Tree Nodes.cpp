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

int findDepth(TreeNode *root)
{
    TreeNode *node = root;
    int depth = 0;
    while (node->left != nullptr)
    {
        depth++;
        node = node->left;
    }
    return depth;
}

bool nodeExistAtIndex(TreeNode *root, int depth, int indexToFind)
{
    if (root == nullptr)
        return false;
    int s = 0, e = pow(2, depth) - 1;
    TreeNode *node = root;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (indexToFind <= mid)
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

int countNodes(TreeNode *root)
{
    int depth = findDepth(root);
    int s = 0, e = pow(2, depth) - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool found = nodeExistAtIndex(root, depth, mid);
        if (found)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return pow(2, depth) - 1 + s;
}

int main()
{
    return 0;
}