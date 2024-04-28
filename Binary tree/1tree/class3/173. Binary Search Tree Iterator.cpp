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
void fillit(TreeNode *root, stack<TreeNode *> &s)
{
    if (root == nullptr)
    {
        return;
    }
    s.push(root);
    fillit(root->left, s);
    return;
}
stack<TreeNode*>s;
BSTIterator(TreeNode *root)
{   
    fillit(root,s);
}

int next()
{
    TreeNode* node=s.top();
    s.pop();
    fillit(node->right,s);
    return node->val;
}

bool hasNext()
{
    if(s.size()!=0)
    {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}