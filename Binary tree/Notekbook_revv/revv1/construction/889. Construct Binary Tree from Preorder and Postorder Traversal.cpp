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

int idx = 0;
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder, int s, int e)
{
    if (s >= e)
        return s > e ? nullptr : new TreeNode(preorder[idx++]);

    TreeNode *root = new TreeNode(preorder[idx++]);
    int i = s;
    while (i <= e and preorder[idx] != postorder[i])
        i++;
    root->left = constructFromPrePost(preorder, postorder, s, i);
    root->right = constructFromPrePost(preorder, postorder, i + 1, e - 1);
    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    return constructFromPrePost(preorder, postorder, 0, preorder.size() - 1);
}

int main()
{
    return 0;
}