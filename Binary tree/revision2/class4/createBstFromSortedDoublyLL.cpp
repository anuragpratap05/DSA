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

void prettyPrintTree(TreeNode *node, string prefix = "", bool isLeft = true)
{
    if (node == nullptr)
    {
        cout << "Empty tree";
        return;
    }

    if (node->right)
    {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left)
    {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

TreeNode *midOfList(TreeNode *head)
{
    TreeNode *curr = head;
    if (curr == nullptr or curr->right == nullptr)
        return curr;
    TreeNode *s = curr;
    TreeNode *f = curr;
    while (f->right != nullptr and f->right->right != nullptr)
    {
        s = s->right;
        f = f->right->right;
    }
    return s;
}

TreeNode *convertDoublyLLtoBst(TreeNode *head)
{
    if (head == nullptr)
        return nullptr;

    TreeNode *root = midOfList(head);
    TreeNode *prev = root->left;
    TreeNode *forw = root->right;
    root->left = root->right = nullptr;
    if (prev != nullptr)
        prev->right = nullptr;
    else
        head = nullptr;
    if (forw != nullptr)
        forw->left = nullptr;
    root->left = convertDoublyLLtoBst(head);
    root->right = convertDoublyLLtoBst(forw);

    return root;
}

int main()
{
    vector<int> nums = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    TreeNode *head = new TreeNode(nums[0]);
    TreeNode *prev = head;
    for (int i = 1; i < nums.size(); i++)
    {
        TreeNode *node = new TreeNode(nums[i]);
        prev->right = node;
        node->left = prev;
        prev = prev->right;
    }
    TreeNode *root = convertDoublyLLtoBst(head);
    prettyPrintTree(root);
    return 0;
}