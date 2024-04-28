#include<bits/stdc++.h>
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
TreeNode *rightmost_node(TreeNode *root, TreeNode *curr)
{
    while (root->right != nullptr and root->right != curr)
    {
        root = root->right;
    }
    return root;
}

vector<TreeNode *> morris_inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    vector<int> ans;
    TreeNode *curr = root;

    TreeNode *a = nullptr, *b = nullptr, *p = nullptr;

    while (curr != nullptr)
    {
        TreeNode *left = curr->left;
        if (left == nullptr)
        {
            //ans.push_back(curr->val);
            if(a==nullptr and p!=nullptr and p->val>curr->val)
            {
                a = p;
                b = curr;
            }
            if (a != nullptr and p != nullptr and p->val > curr->val)
            {
                b = curr;
            }

            p = curr;
            curr = curr->right;
        }
        else
        {
            TreeNode *rmnode = rightmost_node(left, curr);
            if (rmnode->right == nullptr)
            {
                rmnode->right = curr;
                curr = curr->left;
            }
            else
            {
                rmnode->right = nullptr;
                //ans.push_back(curr->val);
                if (a == nullptr and p != nullptr and p->val > curr->val)
                {
                    a = p;
                    b = curr;
                }
                if (a != nullptr and p != nullptr and p->val > curr->val)
                {
                    b = curr;
                }

                p = curr;
                curr = curr->right;
            }
        }
    }

    return {a, b};
}

void recoverTree(TreeNode *root)
{

    vector<TreeNode *> vec = morris_inorder(root);
    TreeNode *a = vec[0];
    TreeNode *b = vec[0];

    swap(a->val, b->val);
    
}

int main()
{
    return 0;
}