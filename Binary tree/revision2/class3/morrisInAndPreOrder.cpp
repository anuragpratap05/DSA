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

TreeNode *rightMostNode(TreeNode *root, TreeNode *curr)
{
    while (root->right != nullptr and root->right != curr)
        root = root->right;

    return root;
}

// sir method
void morrisInorder(TreeNode *root)
{
    TreeNode *curr = root;

    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            TreeNode *rmNode = rightMostNode(l, curr);
            if (rmNode->right == nullptr) // thread creation time
            {
                rmNode->right = curr;
                curr = curr->left;
            }
            else // thread destrot time
            {
                rmNode->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

void morrisPreorder(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr != nullptr)
    {
        TreeNode *l = curr->left;
        if (l == nullptr)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            TreeNode *rmNode = rightMostNode(l, curr);
            if (rmNode->right == nullptr) // thread creation time
            {
                rmNode->right = curr;
                cout << curr->val << " ";
                curr = curr->left;
            }
            else // thread destrot time
            {
                rmNode->right = nullptr;
                // cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

// my method
void morrisInorderMyMethod(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *curr = root;

    while (curr)
    {
        while (curr->left)
        {
            TreeNode *l = curr->left;
            TreeNode *rmNode = rightMostNode(l, curr);
            if (rmNode->right == curr)
            {
                cout << curr->val << " ";
                rmNode->right = nullptr;
                curr = curr = curr->right;
                continue;
            }
            rmNode->right = curr;
            curr = l;
        }
        cout << curr->val << " ";
        curr = curr->right;
    }
}

int main()
{
    return 0;
}
