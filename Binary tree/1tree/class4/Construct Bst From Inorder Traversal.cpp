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

TreeNode *construct(vector<int> &in, int si, int ei)
{
    if (si > ei)
    {
        return nullptr;
    }
    int mid = (si + ei) / 2;
    TreeNode *root = new TreeNode(in[mid]);

    root->left = construct(in, si, mid - 1);
    root->right = construct(in, mid + 1, ei);

    return root;
}

TreeNode *constructFromInOrder(vector<int> &in)
{

    return construct(in,0,in.size()-1);
}

int main()
{
    return 0;
}