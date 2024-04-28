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

TreeNode *rightMostNd(TreeNode *node, TreeNode *curr)
{
    while (node->right != nullptr and node->right != curr)
        node = node->right;
    return node;
}

void morrisInorder(TreeNode *root)
{
    TreeNode *curr = root, *node1 = nullptr, *node2 = nullptr, *prevnd = nullptr;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            // cout << curr->val;
            if (prevnd != nullptr and prevnd->val > curr->val)
            {
                if (node1 == nullptr)
                {
                    node1 = prevnd;
                    node2 = curr;
                }
                else
                {
                    node2 = curr;
                }
            }
            prevnd = curr;

            curr = curr->right;
        }
        else
        {
            TreeNode *rmNd = rightMostNd(l, curr);
            if (rmNd->right == nullptr)
            {
                rmNd->right = curr;
                curr = curr->left;
            }
            else
            {
                rmNd->right = nullptr;
                // cout << curr->val;
                if (prevnd != nullptr and prevnd->val > curr->val)
                {
                    if (node1 == nullptr)
                    {
                        node1 = prevnd;
                        node2 = curr;
                    }
                    else
                    {
                        node2 = curr;
                    }
                }
                prevnd = curr;

                curr = curr->right;
            }
        }
    }
    swap(node1->val, node2->val);
}

void recoverTree(TreeNode *root)
{
    morrisInorder(root);
}

int main()
{
    return 0;
}