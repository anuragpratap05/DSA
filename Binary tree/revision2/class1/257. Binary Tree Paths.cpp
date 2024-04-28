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

void binaryTreePathsHelper(TreeNode *root, string psf, vector<string> &ans)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr and root->right == nullptr)
    {
        psf += to_string(root->val);
        ans.push_back(psf);
        return;
    }

    psf += to_string(root->val) + "->";

    binaryTreePathsHelper(root->left, psf, ans);
    binaryTreePathsHelper(root->right, psf, ans);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string psf = "";
    binaryTreePathsHelper(root, psf, ans);
    return ans;
}

int main()
{
    return 0;
}