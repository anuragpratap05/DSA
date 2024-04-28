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
void print_k_down(TreeNode *root, int k,  TreeNode *block, vector<vector<int>>& final)
{
    if (root == nullptr or root == block)
    {
        return;
    }
    if (k == final.size())
    {
        final.push_back({});
        // ans.push_back(root->val);
        // return;
    }
    final[k].push_back(root->val);
    print_k_down(root->left, k+1,  block, final);
    print_k_down(root->right, k+1,  block, final);
}
int find(TreeNode *root, TreeNode *tar, vector<vector<int>> &final)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root == tar)
    {
        print_k_down(root,0,nullptr,final);
        return 1;
    }


    int l = find(root->left, tar, final);
    if (l != 0)
    {
        print_k_down(root, l, root->left, final);
        return l + 1;
    }

    int r = find(root->right, tar, final);
    if (r != 0)
    {
        print_k_down(root, r, root->right, final);
        return r + 1;
    }
    return 0;
}

vector<vector<int>> The_burning_train(TreeNode *root, TreeNode *tar)
{
    vector<vector<int>> final;
    find(root,tar,final);
    return final;
}

int main()
{
    return 0;
}