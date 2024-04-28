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

TreeNode *middle(TreeNode *root)
{
    TreeNode *s = root;
    TreeNode *f = root;
    while (f->right != nullptr and f->right->right != nullptr)
    {
        s = s->right;
        f = f->right->right;
    }
    return s;
}

TreeNode *SortedDLLToBST_help(TreeNode *head)
{
    if (head == nullptr or head->right == nullptr)
    {
        return head;
    }
    TreeNode *midnode = middle(head);
    TreeNode *p = midnode->left;
    TreeNode *f = midnode->right;
    midnode->left = midnode->right = f->left = nullptr;
    if (p != nullptr)
    {
        p->right = nullptr;
    }
    midnode->left = SortedDLLToBST_help((p == nullptr ? nullptr : head));
    midnode->right = SortedDLLToBST_help(f);
    return midnode;
}

TreeNode *SortedDLLToBST(TreeNode *head)
{
    return SortedDLLToBST_help(head);
}

int main()
{
    return 0;
}