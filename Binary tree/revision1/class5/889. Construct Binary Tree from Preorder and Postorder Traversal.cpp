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
TreeNode *constructFromPrePost_help(vector<int> &preorder, vector<int> &postorder, int s, int e)
{
    if (idx == preorder.size() or s > e)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[idx]);
    int nidx = idx + 1;
    idx++;
    if (nidx == preorder.size() or s == e)
    {
        // idx++;
        return root;
    }

    int i = s;
    while (i <= e and postorder[i] != preorder[nidx])
    {

        i++;
    }

    root->left = constructFromPrePost_help(preorder, postorder, s, i);
    root->right = constructFromPrePost_help(preorder, postorder, i + 1, e - 1);
    return root;
}

TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n = preorder.size();
    return constructFromPrePost_help(preorder, postorder, 0, n - 1);
}

int main()
{
    return 0;
}