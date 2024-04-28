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
TreeNode *construct(vector<int> &preorder, int lr, int rr, vector<int> &vec)
{
    int i = vec[0];
    int ele;
    if (i < preorder.size())
    {
        ele = preorder[i];
    }
    if (ele < lr or ele > rr or i == preorder.size())
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(ele);
    vec[0]++;
    root->left = construct(preorder, lr, ele, vec);
    root->right = construct(preorder, ele, rr, vec);
    return root;
}

bool bstFromPreorder(vector<int> &preorder)
{
    vector<int> vec = {0};
    construct(preorder, -1e9, 1e9, vec);
    if (vec[0] == preorder.size())
    {
        return true;
    }
    return false;
}

bool verifyPreorder(vector<int> &preorder)
{
    return bstFromPreorder(preorder);
    // return isValidBST(root);
}
int main()
{
    // vector<int> preorder = {4, 3, 5, 1, 2, 3};
    // TreeNode *root = bstFromPreorder(preorder);
    // display(root);
    return 0;
}